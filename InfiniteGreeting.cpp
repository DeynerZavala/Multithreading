#include <iostream>
#include <thread>
#include <chrono>

// Hilo que imprime "Hola" infinitamente
void printHola() {
    while (true) {
        std::cout << "Hola\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// Hilo que imprime "Adios" infinitamente
void printAdios() {
    while (true) {
        std::cout << "Adios\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    // Lanzamos los dos hilos
    std::thread hiloHola(printHola);
    std::thread hiloAdios(printAdios);

    // En el main, imprimimos otro saludo infinito
    while (true) {
        std::cout << "Saludo infinito desde el main\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}
