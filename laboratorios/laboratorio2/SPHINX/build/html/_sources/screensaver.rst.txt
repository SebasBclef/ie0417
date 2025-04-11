Funciones internas
------------------

.. function:: colision(b1, b2)

   Detecta si hay una colisión entre dos bolas.

   :param b1: Primera bola a comparar.
   :param b2: Segunda bola a comparar.
   :return: True si las bolas colisionan, False de lo contrario.

.. function:: manejar_colision(b1, b2)

   Maneja la colisión entre dos bolas. Calcula las nuevas velocidades, separa las bolas,
   y con cierta probabilidad genera fragmentos o permite que una bola "coma" a otra.

   :param b1: Primera bola.
   :param b2: Segunda bola.

.. function:: generar_fragmento(bola)

   Genera un pequeño fragmento de una bola con una masa reducida.

   :param bola: Bola original que se fragmenta.

.. function:: comer(grande, pequeña)

   Permite que una bola grande absorba a una más pequeña, aumentando su masa y radio.

   :param grande: Bola más grande que se alimenta.
   :param pequeña: Bola más pequeña que es eliminada.

.. function:: eliminar_fragmentos_pequeños()

   Elimina fragmentos demasiado pequeños con respecto a su masa original.

.. function:: hacer_caer()

   Cambia el movimiento de las bolas para que solo caigan verticalmente.

.. function:: sacudir_bolas()

   Asigna velocidades aleatorias a las bolas para simular un movimiento caótico.
