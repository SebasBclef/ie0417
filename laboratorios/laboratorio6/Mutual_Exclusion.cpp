#include <iostream>
#include <thread>
#include <mutex>

// Se crea contador de forma global para que sea accedido por ambos threads y se vea lo que pasa
int counter;
std::mutex mtx;

// Creamos una funcion para aumentar el contador
void Safe_Incrementar(int &counter) {
    std::lock_guard<std::mutex> lock(mtx);
    for(int i = 0; i < 1000; ++i){
        ++counter;
    }
}

// Funcion principal
int main (){
    // Hilo 1, ejecuta Safe_Incrementar desde el principio
    std::thread t1(Safe_Incrementar,std::ref(counter));
    // Hilo 2, ejecuta Safe_Incrementar desde el principio tambien
    std::thread t2(Safe_Incrementar, std::ref(counter));

    // Ambos hilos comienzan a ejecutarse casi al mismo tiempo

    // Se muestra el valor esperado y el valor real obtenido
    std::cout << "El tamaño esperado para el counter es de 2000" << std::endl;
    std::cout << "El tamaño real del counter es: " << counter << std::endl;

    return 0;
}
