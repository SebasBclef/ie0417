#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

// Se crea un mutex para proteger ready
std::mutex mtx;
// Es la variable de condicion que se usara para esperar/notificar
std::condition_variable cv;

// La condicion para que el hilo espere
bool ready = false;

// Funcion para que el hilo espere a que otro ponga en true el ready
void waitinghThread() {
    std::cout << "Esperando a que otro thread active el ready...\n";
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; }); // Espera hasta que ready sea tru
    std::cout << "ready confirmado";
}


// Funcion la cual se utiliza para activar el ready y que el thread que esta en wait se active
void notifyingThread(){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one(); // Notifica a uno de los hilos en espera
}

int main(){
    // Se crea el primer hilo, el cual va a ejecutar el wait y este esperara hasta que el segundo hilo active el notify
    std::thread t1(waitinghThread);
    // Se crea el segundo hilo el cual activa el ready para que pase el primer hilo
    std::thread t2(notifyingThread);

    // Esto es para que se finalice por completo cada thread
    t1.join();
    t2.join();

    return 0;
}
