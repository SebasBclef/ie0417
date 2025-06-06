/*
===============================================================================
    PROTECCIÓN CONTRA CONDICIONES DE CARRERA CON std::mutex (HELGRIND)
===============================================================================

Este programa es la versión corregida del ejemplo anterior con condición de carrera.

¿QUÉ SE CORRIGE?
----------------
Se protege la sección crítica (la operación sobre la variable compartida `counter`)
utilizando un mutex (`std::mutex`). Esto garantiza que solo un hilo pueda acceder
a dicha variable a la vez, evitando accesos simultáneos peligrosos.

¿CÓMO FUNCIONA?
---------------
Se usa `std::lock_guard<std::mutex>` para adquirir y liberar automáticamente el
candado asociado al mutex `mtx`. Esto evita errores de sincronización y simplifica el código.

BENEFICIOS:
-----------
- Eliminación total de condiciones de carrera.
- Resultado correcto y predecible.
- Verificación con herramientas como Helgrind que no reportan errores.

===============================================================================
*/

#include <iostream>
#include <thread>   // Biblioteca para manejo de hilos
#include <mutex>    // Biblioteca para sincronización (mutex)

int counter = 0;        // Variable compartida entre hilos
std::mutex mtx;         // Mutex global para proteger acceso a 'counter'

void increment() {
    for (int i = 0; i < 100000; ++i) {
        // std::lock_guard adquiere el candado al entrar al bloque
        // y lo libera automáticamente al salir
        std::lock_guard<std::mutex> lock(mtx);  // Protección del acceso a 'counter'
        ++counter;  // Ahora este acceso está sincronizado y es seguro
    }
}

int main() {
    // Se crean dos hilos que ejecutan la misma función
    std::thread t1(increment);
    std::thread t2(increment);

    // Se espera a que ambos hilos terminen
    t1.join();
    t2.join();

    // Imprime el valor final del contador
    std::cout << "Counter: " << counter << std::endl;  // Debería ser exactamente 200000

    return 0;
}

/*
===============================================================================
COMANDOS PARA COMPILACIÓN Y ANÁLISIS CON HELGRIND (Valgrind)
-------------------------------------------------------------------------------
1. Compilar con información de depuración:
    g++ -g -o programa_corregido programa_corregido.cpp

2. Ejecutar con Helgrind:
    valgrind --tool=helgrind ./programa_corregido

SALIDA ESPERADA:
-----------------
Counter: 200000
== ERROR SUMMARY: 0 errors from 0 contexts ==  ✅

Esto indica que no se detectaron condiciones de carrera ni problemas de concurrencia.
===============================================================================
*/
