#include <iostream>
#include <random>

int main(){
    //establecer una semilla específica
    unsigned int seed = 12345;
    std::mt19937 generator (seed);
    
    //generar algunos números aleatorios
    for(int i = 0; i < 5; ++i){
        std::cout << generator() <<std::endl;

    }

}
