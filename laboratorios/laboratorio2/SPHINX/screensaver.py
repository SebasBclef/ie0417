"""
Simulación de colisiones de bolas con fragmentación y "canibalismo".

Este programa utiliza Pygame para mostrar una simulación donde varias bolas se mueven
en la pantalla, rebotan contra las paredes y entre sí. Al colisionar, las bolas pueden:
- rebotar con una física elástica simple,
- fragmentarse en bolas más pequeñas con cierta probabilidad,
- comerse unas a otras si tienen mayor masa.

El usuario puede presionar la barra espaciadora para alternar entre caída vertical
y movimiento aleatorio. Las bolas más pequeñas se eliminan automáticamente si
su masa es muy baja.
"""

import pygame
import sys
import random
import math

pygame.init()

# Configuración de la pantalla
ancho, alto = 800, 600
pantalla = pygame.display.set_mode((ancho, alto))
pygame.display.set_caption("Rebote con fragmentos y bolas comiéndose")

# Colores
NEGRO = (0, 0, 0)

# Parámetros de las bolas
radio = 30
num_bolas = 10  # Número de bolas
bolas = []

# Inicialización de las bolas
for _ in range(num_bolas):
    masa_original = random.randint(1, 5)
    bola = {
        "x": random.randint(radio, ancho - radio),
        "y": random.randint(radio, alto - radio),
        "vel_x": random.choice([-5, -4, -3, 3, 4, 5]),
        "vel_y": random.choice([-5, -4, -3, 3, 4, 5]),
        "color": (random.randint(50, 255), random.randint(50, 255), random.randint(50, 255)),
        "masa": masa_original,
        "radio": radio,
        "masa_original": masa_original
    }
    bolas.append(bola)

# Reloj
reloj = pygame.time.Clock()

# Variables de control para la caída y el "sacudido"
caer = False
sacudir = False

def colision(b1, b2):
    """
    Detecta si hay una colisión entre dos bolas.

    :param b1: Primera bola a comparar.
    :param b2: Segunda bola a comparar.
    :return: True si las bolas colisionan, False de lo contrario.
    """
    dx = b1["x"] - b2["x"]
    dy = b1["y"] - b2["y"]
    distancia = math.hypot(dx, dy)
    return distancia < b1["radio"] + b2["radio"]

def manejar_colision(b1, b2):
    """
    Maneja la colisión entre dos bolas. Calcula las nuevas velocidades, separa las bolas,
    y con cierta probabilidad genera fragmentos o permite que una bola "coma" a otra.

    :param b1: Primera bola.
    :param b2: Segunda bola.
    """
    m1, m2 = b1["masa"], b2["masa"]
    v1_x, v1_y = b1["vel_x"], b1["vel_y"]
    v2_x, v2_y = b2["vel_x"], b2["vel_y"]

    # Fórmulas de colisión elástica simplificada
    v1_x_final = (v1_x * (m1 - m2) + 2 * m2 * v2_x) / (m1 + m2)
    v1_y_final = (v1_y * (m1 - m2) + 2 * m2 * v2_y) / (m1 + m2)
    v2_x_final = (v2_x * (m2 - m1) + 2 * m1 * v1_x) / (m1 + m2)
    v2_y_final = (v2_y * (m2 - m1) + 2 * m1 * v1_y) / (m1 + m2)

    # Asignar nuevas velocidades con amortiguamiento
    b1["vel_x"], b1["vel_y"] = v1_x_final * 0.98, v1_y_final * 0.98
    b2["vel_x"], b2["vel_y"] = v2_x_final * 0.98, v2_y_final * 0.98

    # Separación para evitar solapamiento
    dx = b1["x"] - b2["x"]
    dy = b1["y"] - b2["y"]
    distancia = math.hypot(dx, dy)
    if distancia == 0:
        distancia = 1
    overlap = b1["radio"] + b2["radio"] - distancia
    desplazamiento_x = (dx / distancia) * (overlap / 2)
    desplazamiento_y = (dy / distancia) * (overlap / 2)
    b1["x"] += desplazamiento_x
    b1["y"] += desplazamiento_y
    b2["x"] -= desplazamiento_x
    b2["y"] -= desplazamiento_y

    # Fragmentación aleatoria
    probabilidad_fragmento = 0.05
    if random.random() < probabilidad_fragmento:
        generar_fragmento(b1)
    if random.random() < probabilidad_fragmento:
        generar_fragmento(b2)

    # Comer: si una es más grande
    if b1["masa"] > b2["masa"]:
        probabilidad_comer = min(0.1, b1["masa"] / (b2["masa"] + 1))
        if random.random() < probabilidad_comer:
            comer(b1, b2)
    elif b2["masa"] > b1["masa"]:
        probabilidad_comer = min(0.1, b2["masa"] / (b1["masa"] + 1))
        if random.random() < probabilidad_comer:
            comer(b2, b1)

def generar_fragmento(bola):
    """
    Genera un pequeño fragmento de una bola con una masa reducida.

    :param bola: Bola original que se fragmenta.
    """
    nueva_masa = min(bola["masa"] / 10, 1)
    nueva_radio = radio * nueva_masa / bola["masa"]
    nuevo_x = bola["x"] + random.randint(-10, 10)
    nuevo_y = bola["y"] + random.randint(-10, 10)

    nueva_bola = {
        "x": nuevo_x,
        "y": nuevo_y,
        "vel_x": bola["vel_x"] + random.choice([-2, -1, 1, 2]),
        "vel_y": bola["vel_y"] + random.choice([-2, -1, 1, 2]),
        "color": bola["color"],
        "masa": nueva_masa,
        "radio": nueva_radio,
        "masa_original": bola["masa_original"]
    }
    bolas.append(nueva_bola)

def comer(grande, pequeña):
    """
    Permite que una bola grande absorba a una más pequeña, aumentando su masa y radio.

    :param grande: Bola más grande que se alimenta.
    :param pequeña: Bola más pequeña que es eliminada.
    """
    grande["masa"] += pequeña["masa"]
    grande["radio"] = grande["masa"] ** (1/3) * radio
    bolas.remove(pequeña)

def eliminar_fragmentos_pequeños():
    """
    Elimina fragmentos demasiado pequeños con respecto a su masa original.
    """
    global bolas
    bolas = [bola for bola in bolas if bola["masa"] >= bola["masa_original"] / 10]

def hacer_caer():
    """
    Cambia el movimiento de las bolas para que solo caigan verticalmente.
    """
    global bolas
    for bola in bolas:
        bola["vel_x"] = 0
        bola["vel_y"] = 5

def sacudir_bolas():
    """
    Asigna velocidades aleatorias a las bolas para simular un movimiento caótico.
    """
    global bolas
    for bola in bolas:
        bola["vel_x"] = random.choice([-5, -4, -3, 3, 4, 5])
        bola["vel_y"] = random.choice([-5, -4, -3, 3, 4, 5])

# Bucle principal
while True:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if evento.type == pygame.KEYDOWN:
            if evento.key == pygame.K_SPACE:
                if caer:
                    sacudir_bolas()
                else:
                    hacer_caer()
                caer = not caer

    # Movimiento y rebote
    for bola in bolas:
        bola["x"] += bola["vel_x"]
        bola["y"] += bola["vel_y"]

        if bola["x"] - bola["radio"] <= 0 or bola["x"] + bola["radio"] >= ancho:
            bola["vel_x"] *= -1
        if bola["y"] - bola["radio"] <= 0 or bola["y"] + bola["radio"] >= alto:
            bola["vel_y"] *= -1

    # Colisiones
    bolas_copy = bolas[:]
    for i in range(len(bolas_copy)):
        for j in range(i + 1, len(bolas_copy)):
            b1 = bolas_copy[i]
            b2 = bolas_copy[j]
            if colision(b1, b2):
                manejar_colision(b1, b2)

    eliminar_fragmentos_pequeños()

    # Dibuja todo
    pantalla.fill(NEGRO)
    for bola in bolas:
        pygame.draw.circle(pantalla, bola["color"], (bola["x"], bola["y"]), bola["radio"])

    pygame.display.flip()
    reloj.tick(60)
