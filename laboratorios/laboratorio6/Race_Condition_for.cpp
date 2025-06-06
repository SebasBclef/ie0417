#include <iostream>
#include <thread>

// Se crea contador de forma global para que sea accedido por ambos threads y se vea lo que pasa
int counter;

// Creamos una funcion para aumentar el contador
void incrementar() {
    for(int i = 0; i < 1000; ++i){
        ++counter; // Incremento no atomico
    }
}

// Funcion principal
int main (){
    // Hilo 1, ejecuta incrementar desde el principio
    std::thread t1(incrementar);
    // Hilo 2, ejecuta incrementar desde el principio tambien
    std::thread t2(incrementar);

    // Ambos hilos comienzan a ejecutarse casi al mismo tiempo

    // Se muestra el valor esperado y el valor real obtenido
    std::cout << "El tamaño esperado para el counter es de 2000" << std::endl;
    std::cout << "El tamaño real del counter es: " << counter << std::endl;

    return 0;
}
