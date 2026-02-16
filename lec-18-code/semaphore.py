import threading
import time
import random

BUFFER_SIZE = 5
buffer = []

empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)
mutex = threading.Lock()

def producer():
    item = 0
    while True:
        empty.acquire()
        mutex.acquire()

        buffer.append(item)
        print("Produced:", item)
        item += 1

        mutex.release()
        full.release()

        time.sleep(1)

def consumer():
    while True:
        full.acquire()
        mutex.acquire()

        item = buffer.pop(0)
        print("Consumed:", item)

        mutex.release()
        empty.release()

        time.sleep(2)

p = threading.Thread(target=producer)
c = threading.Thread(target=consumer)

p.start()
c.start()

p.join()
c.join()
