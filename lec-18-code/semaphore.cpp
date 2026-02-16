
---

# 💻 Working C++ Code (Using Semaphore)

```cpp
#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <mutex>

using namespace std;

const int BUFFER_SIZE = 5;

vector<int> buffer;
counting_semaphore<5> empty(BUFFER_SIZE);
counting_semaphore<5> full(0);
mutex mtx;

void producer() {
    int item = 0;
    while (true) {
        empty.acquire();          // wait(empty)
        mtx.lock();               // wait(mutex)

        buffer.push_back(item);
        cout << "Produced: " << item << endl;
        item++;

        mtx.unlock();             // signal(mutex)
        full.release();           // signal(full)

        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consumer() {
    while (true) {
        full.acquire();           // wait(full)
        mtx.lock();               // wait(mutex)

        int item = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << item << endl;

        mtx.unlock();             // signal(mutex)
        empty.release();          // signal(empty)

        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {
    thread p(producer);
    thread c(consumer);

    p.join();
    c.join();
}
