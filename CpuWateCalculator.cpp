/**
* Threads that waste CPU cycles
 */
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <vector>


// a simple function that wastes CPU cycles "forever"
void cpu_waster(int thread_id) {
    int a, b;
        a = 0;
        b = 0;
        std::cout << "Hilo " << thread_id << " - Ingresa 1° numero a sumar: ";
        std::cin >> a;
        std::cout << "Hilo " << thread_id << " - Ingresa 2° numero a sumar: ";
        std::cin >> b;
        std::cout << "Hilo " << thread_id << " - El resultado es: " << a+b << std::endl;
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %d\n", std::this_thread::get_id());

    std::vector<std::thread> threads;
    for(int i = 0; i < 2; i++) {
        threads.emplace_back(cpu_waster,i+1);
    }

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}