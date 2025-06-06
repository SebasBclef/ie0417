/*
===============================================================================
    DETECCIÓN DE CONDICIONES DE CARRERA CON THREADSANITIZER (TSan)
===============================================================================

ThreadSanitizer (TSan) es una herramienta que detecta errores de concurrencia,
principalmente **condiciones de carrera** en programas que usan múltiples hilos.

¿QUÉ ES UNA CONDICIÓN DE CARRERA?
----------------------------------
Es una situación en la que dos o más hilos acceden a una misma variable al mismo tiempo,
y al menos uno de ellos realiza una escritura sin una adecuada sincronización.
Esto puede generar resultados no deterministas y difíciles de depurar.

¿QUÉ HACE TSan?
----------------
- Intercepta operaciones de lectura/escritura en memoria compartida.
- Detecta accesos simultáneos sin protección (por ejemplo, sin `mutex`).
- Informa con precisión las líneas de código involucradas.

Este programa genera intencionalmente una condición de carrera sobre la variable global `counter`,
al incrementar su valor desde dos hilos concurrentes sin sincronización.

===============================================================================
*/

#include <iostream>
#include <thread>  // Necesario para usar std::thread

// Variable global compartida entre hilos
int counter = 0;

// Función que incrementa el contador muchas veces
void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter;  // ← CONDICIÓN DE CARRERA: acceso simultáneo sin sincronización
    }
}

int main() {
    // Se crean dos hilos que ejecutan la misma función
    std::thread t1(increment);
    std::thread t2(increment);

    // Espera a que ambos hilos finalicen
    t1.join();
    t2.join();

    // Resultado del contador (no será siempre 200000)
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}

/*
===============================================================================
COMANDOS PARA COMPILAR Y EJECUTAR CON THREADSANITIZER (TSan)
-------------------------------------------------------------------------------
1. Compilar con soporte para TSan:
    g++ -fsanitize=thread -g -o programa programa.cpp

2. Ejecutar el programa:
    ./programa

TSan mostrará un mensaje de advertencia indicando que ha detectado
una condición de carrera, con la línea exacta donde ocurre el conflicto.
===============================================================================
*/
