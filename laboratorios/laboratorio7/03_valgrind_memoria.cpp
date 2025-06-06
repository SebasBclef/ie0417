/*
===============================================================================
    ANÁLISIS DE MEMORIA EN C++ — ERRORES DETECTABLES CON VALGRIND (Memcheck)
===============================================================================

Herramientas como Memcheck de Valgrind permiten detectar errores comunes
en el manejo de memoria dinámica:

1. **Fugas de memoria (memory leaks)**:
   - Ocurren cuando se reserva memoria con `new` pero nunca se libera con `delete`.
   - Provoca que el sistema pierda acceso a esa memoria hasta que finalice el programa.

2. **Memoria no inicializada**:
   - Se usa una dirección de memoria antes de asignarle un valor válido.
   - Puede provocar comportamientos inesperados.

3. **Acceso fuera de los límites**:
   - Se intenta acceder a posiciones de un arreglo que están fuera del rango válido.
   - Esto puede causar fallos, corrupción de datos u otros errores difíciles de rastrear.

Este código contiene ejemplos de cada uno de estos casos para su análisis con herramientas de depuración de memoria.
*/

#include <iostream>

int main() {

    // =========================================================================
    // 1. ERROR: Fuga de memoria — se reserva memoria dinámica pero no se libera
    // =========================================================================
    int* p1 = new int[10];         // Se reserva un bloque de 10 enteros
    // No se hace delete[] p1 → ¡Fuga de memoria!
    // Esta línea intencionalmente no libera la memoria

    // =========================================================================
    // 2. ERROR: Memoria no inicializada — se accede antes de asignar valor
    // =========================================================================
    int* p2 = new int[10];         // Se reserva memoria
    std::cout << p2[0] << std::endl;  // ¡p2[0] no ha sido inicializado!
    delete[] p2;                   // Aquí sí se libera la memoria correctamente

    // =========================================================================
    // 3. ERROR: Acceso fuera de los límites de un arreglo
    // =========================================================================
    int array[10];                // Arreglo con índices válidos de 0 a 9
    array[10] = 5;                // ERROR: índice fuera de rango (acceso inválido)

    return 0;
}
