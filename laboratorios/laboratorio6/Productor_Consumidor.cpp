#include <iostream>                      // Entrada y salida est�ndar
#include <thread>                        // Para crear hilos
#include <vector>                        // Para almacenar hilos en un vector
#include <queue>                         // Para el buffer compartido (FIFO)
#include <mutex>                         // Para proteger secciones cr�ticas
#include <condition_variable>            // Para coordinaci�n entre hilos
#include <semaphore>                     // Sem�foros de conteo (C++20)
#include <chrono>                        // Para pausas y tiempos

using namespace std;

// Constante: capacidad m�xima del buffer
constexpr int BUFFER_SIZE = 10;

// Cola compartida que simula el buffer
std::queue<int> buffer;

// Mutex para proteger el acceso concurrente al buffer
std::mutex mtx;

// Variables de condici�n para productores y consumidores
std::condition_variable cv_producer, cv_consumer;


// Sem�foros de conteo:
// - `empty_slots` controla cu�ntos espacios vac�os hay en el buffer
// - `full_slots` controla cu�ntos elementos hay disponibles para consumir
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Comienza con todos los espacios vac�os
std::counting_semaphore<BUFFER_SIZE> full_slots(0);            // Comienza sin elementos

// Funci�n que simula un productor
void producer(int id, int num_tasks) {
    for (int i = 0; i < num_tasks; ++i) {
        // Simula producir un elemento (dato ficticio)
        int item = id * 100 + i;

        // Espera hasta que haya un espacio disponible
        empty_slots.acquire(); // Decrementa el contador de espacios libres

        // Secci�n cr�tica: acceso exclusivo al buffer
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item); // Inserta el item en el buffer
            std::cout << "Producer " << id << " produced item " << item << std::endl;
        }

        // Se�ala que hay un nuevo elemento disponible
        full_slots.release();      // Incrementa el contador de elementos disponibles
        cv_consumer.notify_one();  // Notifica a un consumidor que puede continuar
    }
}

// Funci�n que simula un consumidor
void consumer(int id) {
    while (true) {
        // Espera hasta que haya al menos un elemento para consumir
        full_slots.acquire(); // Decrementa el contador de elementos disponibles

        // Secci�n cr�tica protegida por mutex
        std::unique_lock<std::mutex> lock(mtx);

        // Espera activa hasta que haya elementos (por seguridad extra)
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        // Toma el elemento del buffer
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed item " << item << std::endl;

        // Libera el mutex antes de liberar espacio y simular procesamiento
        lock.unlock();

        // Se�ala que hay un espacio libre disponible
        empty_slots.release();     // Incrementa el contador de espacios vac�os
        cv_producer.notify_one();  // Notifica a un productor

        // Simula tiempo de procesamiento
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Funci�n principal
int main() {
    const int num_producers = 2;             // N�mero de hilos productores
    const int num_consumers = 3;             // N�mero de hilos consumidores
    const int num_tasks_per_producer = 10;   // Cu�ntas tareas produce cada productor

    // Vectores para guardar los hilos
    std::vector<std::thread> producers, consumers;

    // Crear hilos productores
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer, i, num_tasks_per_producer);
    }

    // Crear hilos consumidores
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    // Esperar a que los productores terminen
    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    // Permitir que los consumidores terminen de procesar (tiempo artificial)
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // En un caso ideal, aqu� se deber�a se�alizar a los consumidores para terminar
    std::cout << "All producers have finished." << std::endl;

    return 0;
}
