/*
===============================================================================
    ANÁLISIS DE CONCURRENCIA CON HELGRIND (Valgrind)
===============================================================================

Helgrind es una herramienta del conjunto de Valgrind diseñada para detectar errores
en programas multihilo, especialmente **condiciones de carrera (race conditions)**.

CONDICIÓN DE CARRERA:
----------------------
Se presenta cuando dos o más hilos acceden simultáneamente a una misma variable,
y al menos uno de ellos realiza una escritura sin mecanismos adecuados de sincronización,
como mutexes. Esto genera resultados no deterministas, errores intermitentes y
comportamientos impredecibles, difíciles de depurar sin herramientas especializadas.

¿QUÉ DETECTA HELGRIND?
------------------------
- Accesos simultáneos a variables sin sincronización.
- Errores por escritura concurrente.
- Lecturas/escrituras cruzadas sin protección de memoria compartida.

VENTAJA:
--------
Helgrind funciona sin necesidad de compilar con flags especiales, solo se requiere
que el binario contenga información de depuración (`-g`).

===============================================================================
*/

#include <iostream>
#include <thread>  // Permite trabajar con múltiples hilos

// Variable compartida entre hilos
int counter = 0;

// Función que incrementa el valor del contador muchas veces
void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter;  // ← CONDICIÓN DE CARRERA: acceso no sincronizado a 'counter'
    }
}

int main() {
    // Se crean dos hilos que ejecutan la función increment() al mismo tiempo
    std::thread t1(increment);
    std::thread t2(increment);

    // join() bloquea el hilo principal hasta que t1 y t2 finalicen su ejecución
    t1.join();
    t2.join();

    // El valor final de 'counter' probablemente no será 200000 debido a la condición de carrera
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}

/*
===============================================================================
COMANDOS PARA COMPILACIÓN Y ANÁLISIS CON HELGRIND:
-------------------------------------------------------------------------------
1. Compilar con información de depuración:
    g++ -g -o programa programa.cpp

2. Ejecutar con Helgrind:
    valgrind --tool=helgrind ./programa

Helgrind analizará todos los accesos concurrentes y mostrará advertencias como:
    - "Possible data race"
    - Líneas específicas donde ocurrió el acceso conflictivo
    - Hilo involucrado (por ejemplo: thread #1 vs thread #2)

Esto permite detectar errores de concurrencia complejos que pueden pasar desapercibidos
en pruebas convencionales.
===============================================================================
*/
