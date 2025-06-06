/*
===============================================================================
    DEMOSTRACIÓN DE TIPOS DE ERRORES EN UN PROGRAMA EN C++
===============================================================================
1. Errores de sintaxis
2. Errores de ejecución
3. Errores lógicos
*/
/*
============================================================
    DEMOSTRACIÓN DE TIPOS DE ERRORES EN UN PROGRAMA EN C++
============================================================

Este programa tiene como propósito mostrar intencionalmente
los tres tipos principales de errores que pueden ocurrir en
la programación:

1. ERRORES DE SINTAXIS:
   - Son errores en la forma en que se escribe el código.
   - Rompen las reglas del lenguaje de programación.
   - Ejemplos: falta de punto y coma, paréntesis mal cerrados,
     uso incorrecto de palabras clave, etc.
   - Estos errores impiden que el código compile.

2. ERRORES DE TIEMPO DE EJECUCIÓN:
   - Son errores que ocurren mientras el programa está corriendo.
   - Generalmente se deben a condiciones inesperadas.
   - Ejemplos: división por cero, acceder fuera de los límites de un arreglo.

3. ERRORES LÓGICOS:
   - Son errores en la lógica del algoritmo.
   - No impiden que el programa compile o se ejecute, pero producen resultados incorrectos.
   - Ejemplos: condiciones erróneas, bucles mal definidos, cálculos incorrectos.

Este código contiene al menos un ejemplo de cada uno de estos errores,
intencionalmente, para fines educativos.
*/

#include <iostream>  // Librería estándar para entrada/salida

int main() {

    // ===============================
    // ERROR DE SINTAXIS (INTENCIONAL)
    // ===============================
    // Falta un punto y coma al final de esta línea (esto causará un error de compilación)
    std::cout << "Iniciando el programa" << std::endl  // ← Falta el ;

    // ==================================
    // ERROR DE TIEMPO DE EJECUCIÓN
    // ==================================
    // División por cero: 'divisor' tiene valor 0, lo que provoca un fallo en tiempo de ejecución
    int divisor = 0;
    int resultado = 10 / divisor;

    // ===============================
    // ERROR LÓGICO EN UN BUCLE
    // ===============================
    // El bucle intenta acceder a índice 5 del arreglo, que no existe (índices válidos: 0 a 4)
    // Además, la condición del bucle está mal escrita y causa que se acceda a una posición inválida
    int arreglo[5] = {1, 2, 3, 4, 5};
    int suma = 0;

    // Este bucle debería ser: for (int i = 0; i < 5; ++i)
    for (int i = 0; i <= 5; ++i) {
        suma += arreglo[i];  // Posible acceso fuera de los límites del arreglo
    }

    // ===============================
    // SALIDA FINAL (podría no ejecutarse si hay errores previos)
    // ===============================
    std::cout << "Suma de los elementos del arreglo: " << suma << std::endl;

    return 0;
}
