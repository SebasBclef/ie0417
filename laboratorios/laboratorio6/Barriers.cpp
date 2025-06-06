#include <iostream>
#include <thread>
#include <barrier>

// Esta es la barrera que esperara hasta que 3 threads entren
std::barrier sync_point(3);

// Funcion la cual hace algo antes de la barrera sea pasada, y que hace algo mas despues de que la barrera se pasa
void threadFunction(){
    std::cout << "Entro hilo esperando...\n";
    // Espera hasta que lleguen los 3 threads para dejarlos pasar
    sync_point.arrive_and_wait();
    std::cout << "barrera pasada \n";
}

int main(){
    // Primer hilo en entrar
    std::thread t1(threadFunction);
    // Segundo hilo en entrar
    std::thread t2(threadFunction);
    // Tercer hilo en entrar
    std::thread t3(threadFunction);

    // Espera hasta que todos los hilos finalizen
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
