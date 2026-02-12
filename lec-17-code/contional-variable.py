import threading
import time

condition = threading.Condition()
ready = False

def worker():
    global ready
    with condition:
        condition.wait_for(lambda: ready)
        print("Worker thread proceeding...")

def signaler():
    global ready
    time.sleep(2)
    with condition:
        ready = True
        condition.notify()

t1 = threading.Thread(target=worker)
t2 = threading.Thread(target=signaler)

t1.start()
t2.start()

t1.join()
t2.join()
