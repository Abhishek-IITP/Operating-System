#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::cout << "Worker thread proceeding...\n";
}

void signaler() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one();
}

int main() {
    std::thread t1(worker);
    std::thread t2(signaler);

    t1.join();
    t2.join();
    return 0;
}
