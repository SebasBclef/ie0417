/*
===============================================================================
    ERRORES DE MEMORIA EN C++ — DETECCIÓN CON VALGRIND (Memcheck)
===============================================================================

Este programa contiene varios errores de manejo de memoria, diseñados
intencionalmente para ser detectados con la herramienta Valgrind.

TIPOS DE ERRORES PRESENTES:
----------------------------
1. Fuga de memoria: se reserva memoria con `new[]` pero no se libera con `delete[]`.
2. Memoria no inicializada: se accede a una posición antes de asignarle un valor.
3. Acceso fuera de los límites: se accede a un índice no válido de un arreglo estático.

COMANDOS PARA ANALIZAR CON VALGRIND:
-------------------------------------
1. Compilar con símbolos de depuración:
    g++ -g -o errores_memoria errores_memoria.cpp

2. Ejecutar con Valgrind:
    valgrind --leak-check=full ./errores_memoria

===============================================================================
*/

#include <iostream>

void funcion1() {
    // ============================================================
    // 1. ERROR: Fuga de memoria — se reserva pero no se libera
    // ============================================================
    int* p = new int[10]; // Se asigna un bloque de 10 enteros dinámicamente
    // No se hace delete[] p → se produce una pérdida de memoria

    // ============================================================
    // 2. ERROR: Memoria no inicializada — se accede sin valor asignado
    // ============================================================
    std::cout << p[0] << std::endl; // Se imprime un valor sin inicializar

    // ============================================================
    // 3. ERROR: Acceso fuera de los límites del arreglo
    // ============================================================
    int array[5];       // Arreglo de 5 enteros (índices válidos: 0 a 4)
    array[5] = 10;       // Acceso inválido al índice 5 (fuera de rango)
}

int main() {
    funcion1();         // Llama a la función con errores intencionados
    return 0;
}
