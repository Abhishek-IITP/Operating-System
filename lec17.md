# 🔔 Condition Variables & Semaphores to Synchronize Threads

---

## 🌀 Busy Waiting

### What is Busy Waiting?
- Thread continuously check karta rehta hai ek **flag variable**
- CPU idle nahi hota, continuously loop chalta rehta hai
- Isse CPU cycles waste hote hain

Example idea:

```CPP
while(flag == false) {
// keep checking
}
```

❌ Problem:
- CPU waste
- Inefficient
- High contention

---

# 🔄 Condition Variables

## 📌 What is a Condition Variable?

- Ek **synchronization primitive**
- Thread ko allow karta hai wait karne ke liye
- Jab tak specific condition true na ho

---

## 🔐 Important Points

- Always works with a **mutex (lock)**
- Thread must:
  1. Acquire lock
  2. Check condition
  3. Call `wait()`

- `wait()`:
  - Lock release karta hai
  - Thread ko sleep state me daal deta hai

- Jab koi thread `signal()` karta hai:
  - Waiting thread wake hota hai
  - Lock dubara acquire karta hai
  - Execution continue karta hai

---

## ❓ Why Use Condition Variable?

- Busy waiting avoid karta hai
- CPU waste nahi hota
- Better synchronization
- No unnecessary contention

---

## 🔁 Logical Flow

Thread A:
- lock()
- while(condition == false)
  - wait()
- critical section
- unlock()

Thread B:
- lock()
- modify condition
- signal()
- unlock()

---

# 🚦 Semaphores

## 📌 What is a Semaphore?

- Ek **integer synchronization variable**
- Represents number of available resources

---

## 🔢 Types of Semaphores

### 1️⃣ Binary Semaphore
- Value: 0 or 1
- Acts like a **Mutex**
- Single resource control karta hai

---

### 2️⃣ Counting Semaphore
- Value: 0 to N
- N = Number of resource instances
- Multiple threads simultaneously critical section me ja sakte hain (up to N)

---

## ⚙️ Working of Semaphore

### Two Main Operations

### 🔽 wait() / P()
- Semaphore value decrement hoti hai
- Agar value < 0:
  - Process block ho jaata hai
  - Waiting queue me daal diya jata hai

---

### 🔼 signal() / V()
- Semaphore value increment hoti hai
- Agar waiting queue me process hai:
  - Ek process wakeup hota hai
  - Ready queue me daal diya jata hai

---

## 🧩 Internal Working Conceptually

1. Semaphore S ke paas ek integer value hoti hai
2. wait():
   - S = S - 1
   - Agar S < 0 → process block
3. signal():
   - S = S + 1
   - Agar koi blocked process hai → wakeup

---
```
           Semaphore S (Value = N)
                   |
                   v
          -----------------
          |   wait()      |
          | S = S - 1     |
          | if S < 0      |
          |   block()     |
          -----------------
                   |
                   v
             Critical Section
                   |
                   v
          -----------------
          |   signal()    |
          | S = S + 1     |
          | wakeup()      |
          -----------------

```

## 🧠 Blocking vs Busy Waiting

Old implementation:
- wait() → busy loop

Improved implementation:
- wait() → block process
- signal() → wakeup process

👉 Isse CPU efficient ban jaata hai

---

## 🧠 Key Difference: Mutex vs Semaphore

| Feature | Mutex | Binary Semaphore | Counting Semaphore |
|----------|--------|------------------|--------------------|
| Value | Locked / Unlocked | 0 / 1 | 0 to N |
| Resource Count | Single | Single | Multiple |
| Ownership | Yes | No strict ownership | No |
| Use Case | Critical Section | Locking | Limited resources |

---

## 🧠 One-Line Revision

**Condition variables block threads until a condition becomes true, and semaphores control access to limited shared resources using an integer counter**
