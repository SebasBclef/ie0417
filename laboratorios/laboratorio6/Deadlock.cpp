#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Se definen dos mutex que representan dos recursos compartidos
std::mutex mtx1, mtx2;

// Función que simula el trabajo del hilo A
void threadA() {
    // Hilo A adquiere primero el mutex 1 (recurso 1)
    std::lock_guard<std::mutex> lock1(mtx1);

    // Simula una operación que toma tiempo
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Luego adquiere el mutex 2 (recurso 2)
    std::lock_guard<std::mutex> lock2(mtx2);

    // Ambos recursos han sido adquiridos exitosamente
    std::cout << "Hilo A ha adquirido ambos recursos." << std::endl;
}

// Función que simula el trabajo del hilo B
void threadB() {
    // Hilo B también adquiere primero el mutex 1 (igual que A)
    std::lock_guard<std::mutex> lock1(mtx1);

    // Simula una operación que toma tiempo
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Luego adquiere el mutex 2
    std::lock_guard<std::mutex> lock2(mtx2);

    // Ambos recursos han sido adquiridos exitosamente
    std::cout << "Hilo B ha adquirido ambos recursos." << std::endl;
}

int main() {
    // Se lanzan los hilos A y B
    std::thread t1(threadA);
    std::thread t2(threadB);

    // Se espera a que ambos hilos terminen
    t1.join();
    t2.join();

    // Mensaje final indicando que no hubo deadlock
    std::cout << "Ambos hilos han terminado sin deadlock." << std::endl;
    return 0;
}
