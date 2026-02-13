# 🏭 Producer–Consumer Problem (Bounded Buffer Problem)

---

## 📌 What is Producer–Consumer Problem?

Do types ke threads hote hain:

1️⃣ **Producer Thread**  
- Data produce karta hai  
- Buffer me insert karta hai  

2️⃣ **Consumer Thread**  
- Buffer se data remove karta hai  
- Data consume karta hai  

---

## 🚧 Problem Statement

- Shared resource = **Buffer (Critical Section)**
- Synchronization required between producer & consumer

### Conditions:

- Producer must **NOT insert** data when buffer is **FULL**
- Consumer must **NOT remove** data when buffer is **EMPTY**

Agar synchronization nahi hoga:
- Race condition ho sakti hai
- Data overwrite ho sakta hai
- Inconsistent state aa sakti hai

---

## 🧠 Critical Section Diagram

          +----------------------+
          |      Producer        |
          +----------------------+
                    |
                    v
           +------------------+
           |  Shared Buffer   |   ← Critical Section
           +------------------+
                    ^
                    |
          +----------------------+
          |      Consumer        |
          +----------------------+



---

# ✅ Solution Using Semaphores

We use 3 semaphores:

---

## 1️⃣ mutex (Binary Semaphore)
- Used for **mutual exclusion**
- Ensures:
  - Ek time pe sirf ek thread buffer access kare

Initial value:

mutex = 1


---

## 2️⃣ empty (Counting Semaphore)
- Tracks **empty slots**
- Initial value:

empty = n (buffer size)


---

## 3️⃣ full (Counting Semaphore)
- Tracks **filled slots**
- Initial value:

full = 0


---

# 🔄 Algorithm (From Your Image Logic)

## 🟢 Producer
```
do {
wait(empty); // Wait until empty > 0
wait(mutex); // Enter critical section
} while(1);
```
// Add item to buffer

signal(mutex);    // Exit critical section
signal(full);     // Increment full count

---

## 🔵 Consumer

```
do {
wait(full); // Wait until full > 0
wait(mutex); // Enter critical section
} while(1);
```

// Remove item from buffer

signal(mutex);    // Exit critical section
signal(empty);    // Increment empty count


## 🧠 How It Works Internally

Producer:
    empty-- → mutex lock → add item → mutex unlock → full++

Consumer:
    full-- → mutex lock → remove item → mutex unlock → empty++


