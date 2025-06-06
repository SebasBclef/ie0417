#include <iostream>
#include <thread>
#include <vector>

// Se crea el vector en el cual los hilos van a escribir
std::vector<int> myList;

// Se crea la primera funcion la cual escribe en el vector un 1, y lo incrementa cada vez que entra
void agregar1() {
    for(int i = 0; i < 100; ++i){
        myList.push_back(1);
    }
}

// Se crea la segunda funcion la cual escribe en el vector un 1, y lo incrementa cada vez que entra
void agregar2() {
    for(int i = 0; i < 100; ++i){
        myList.push_back(2);
    }
}

// Se genera el main en el cual se llamaran las funciones
int main() {
    // Se genera el primer hilo, el cual llama a agregar1
    std::thread h1(agregar1);
    // Se genera el segundo hilo, el cual llama a agregar2
    std::thread h2(agregar2);

    // Se muestra el valor esperado y el valor real
    std::cout << "El tamaño esperado de myList es 200" << std::endl;
    std::cout << "El tamaño real de myList es: " << myList.size() << std::endl;
    return 0;
}
