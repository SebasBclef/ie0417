/*
===============================================================================
    DETECCIÓN DE ERRORES DE MEMORIA CON AddressSanitizer (ASan)
===============================================================================

AddressSanitizer (ASan) es una herramienta de detección de errores de memoria
que permite identificar errores comunes durante la ejecución de programas C/C++,
como:

1. **Acceso fuera de los límites** (out-of-bounds):
   - Se intenta acceder a una posición fuera del rango válido de un arreglo.

2. **Uso después de liberar memoria** (use-after-free):
   - Se accede a memoria que ya ha sido liberada con `delete` o `delete[]`.

3. **Uso de memoria no inicializada**:
   - Aunque este ejemplo no lo incluye explícitamente, ASan también puede detectar este tipo de error.

ASan funciona interceptando las operaciones de memoria, manteniendo un "shadow memory"
para monitorear qué regiones están válidas y cuáles han sido liberadas o están fuera de límites.

Para usar ASan se debe compilar el programa con la bandera `-fsanitize=address`.
Esto le indica al compilador que incluya el runtime necesario para la verificación.

===============================================================================
*/

#include <iostream>

void funcion1() {
    // ============================================================
    // 1. ERROR: Acceso fuera de los límites de un arreglo dinámico
    // ============================================================
    int* p = new int[10];    // Reserva dinámica de 10 enteros (índices 0 a 9)
    p[10] = 5;               // ERROR: índice 10 no existe (fuera de rango)
    delete[] p;              // Libera correctamente la memoria

    // ============================================================
    // 2. ERROR: Uso de memoria después de ser liberada (use-after-free)
    // ============================================================
    int* q = new int[10];    // Reserva dinámica de 10 enteros
    delete[] q;              // Se libera la memoria
    std::cout << q[0] << std::endl;  // ERROR: se accede a memoria ya liberada
}

int main() {
    funcion1();              // Llama a la función con errores intencionados
    return 0;
}

/*
===============================================================================
COMANDOS PARA COMPILACIÓN Y EJECUCIÓN CON AddressSanitizer:
-------------------------------------------------------------------------------
1. Compilar el programa con soporte para ASan:
    g++ -fsanitize=address -g -o programa programa.cpp

2. Ejecutar el programa normalmente:
    ./programa

ASan detectará automáticamente accesos inválidos y mostrará mensajes detallados
con líneas exactas y causas de los errores.
===============================================================================
*/
