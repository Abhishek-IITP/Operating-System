#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<3> sem(3);

void worker(int id) {
    sem.acquire();
    std::cout << "Thread " << id << " entered critical section\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " leaving\n";
    sem.release();
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    std::thread t4(worker, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
