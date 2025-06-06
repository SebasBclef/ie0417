/*
============================================================================
    DEMOSTRACIÓN DE USO DEL DEPURADOR GDB Y ERROR DE TIEMPO DE EJECUCIÓN
============================================================================

Este ejemplo está diseñado para mostrar cómo utilizar el depurador GDB
para detectar un error de tiempo de ejecución: la división por cero.

Pasos para compilar y depurar:

1. Compilación con símbolos de depuración:
    g++ -g -o programa programa.cpp

2. Iniciar GDB:
    gdb programa

3. Comandos útiles dentro de GDB:
    run                   -> Ejecuta el programa
    break funcion1        -> Coloca un punto de ruptura en la función `funcion1`
    continue              -> Continúa la ejecución hasta el siguiente punto de ruptura
    next                  -> Ejecuta la siguiente línea (sin entrar en funciones)
    print a               -> Muestra el valor de la variable `a`
    step                  -> Ejecuta la siguiente instrucción y entra en funciones si es necesario
    backtrace             -> Muestra la pila de llamadas
    continue              -> Reanuda la ejecución

Este código contiene una división por cero en `funcion1`, la cual
provocará un fallo en tiempo de ejecución y será analizada con GDB.
*/

#include <iostream>  // Para entrada/salida estándar

// ===================================
// Función con error de tiempo de ejecución
// ===================================
void funcion1() {
    int a = 5;         // Variable con valor entero 5
    int b = 0;         // Variable con valor 0 (causará el error)
    int c = a / b;     // ERROR: División por cero

    // Esta línea probablemente no se ejecutará debido al error anterior
    std::cout << "Resultado: " << c << std::endl;
}

// ===================================
// Función principal
// ===================================
int main() {
    // Mensaje de inicio
    std::cout << "Iniciando el programa" << std::endl;

    // Llamada a función con error
    funcion1();

    // Mensaje final (probablemente no se alcanzará)
    std::cout << "Finalizando el programa" << std::endl;

    return 0;
}
