#include <iostream>
#include <thread>
#include <semaphore>  //  Necesario para std::counting_semaphore
#include <chrono>

std::counting_semaphore<1> sem(1); // Semáforo binario con contador inicial en 1

void accessResource(int id) {
    std::cout << "Hilo " << id << " esperando semaforo...\n";
    sem.acquire();  // Espera hasta que el semáforo esté disponible (contador > 0)

    std::cout << "Hilo " << id << " ENTRA a la seccion critica\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simula trabajo
    std::cout << "Hilo " << id << " SALE de la seccion critica\n";

    sem.release();  // Libera el semáforo (incrementa contador)
}

int main() {
    std::thread t1(accessResource, 1);
    std::thread t2(accessResource, 2);
    std::thread t3(accessResource, 3);


    t1.join();
    t2.join();
    t3.join();

    return 0;
}
