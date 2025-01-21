/**
* Threads that waste CPU cycles
 */
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <vector>


// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    printf("CPU Waster Process ID: %d\n", getpid());
    printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
    while(true) continue;
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %d\n", std::this_thread::get_id());

    std::vector<std::thread> threads;
    for(int i = 0; i < 6; i++) {
        threads.emplace_back(cpu_waster);
    }

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}