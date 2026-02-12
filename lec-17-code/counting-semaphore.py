import threading
import time

sem = threading.Semaphore(3)

def worker(id):
    sem.acquire()
    print(f"Thread {id} entered")
    time.sleep(2)
    print(f"Thread {id} leaving")
    sem.release()

for i in range(5):
    threading.Thread(target=worker, args=(i,)).start()
