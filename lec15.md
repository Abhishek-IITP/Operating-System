# 🔄 What is Concurrency?

- **Concurrency** means handling **multiple instruction sequences at the same time**
- OS concurrency tab hoti hai jab:
  - Multiple processes **OR**
  - Multiple threads  
  execute ho rahe hote hain

> Concurrency ≠ Parallelism  
> - **Concurrency** → Multiple tasks *in progress*  
> - **Parallelism** → Multiple tasks *executing at the exact same time* (multi-core)

---

## 🧵 What is a Thread?

- Thread is a **single sequence of execution** within a process
- It is an **independent path of execution**
- Thread ko **lightweight process** bhi kaha jata hai
- Threads process ke:
  - Code
  - Data
  - Heap  
  share karte hain
- Har thread ka apna:
  - Program Counter
  - Registers
  - Stack hota hai

### Why Threads?
- Independent tasks ko parallel / concurrent run karne ke liye

### Examples
- Multiple tabs in a browser
- Text editor (typing + autosave)
- Video player (play + buffer)

---

## ⚙️ Benefits of Multithreading

---

### 1️⃣ Responsiveness
- Interactive applications **freeze nahi hoti**
- Ek thread busy ho tab bhi dusra thread user input handle kar leta hai

**Example:**  
Browser me ek tab slow load ho raha ho, baaki tabs responsive rehte hain

---

### 2️⃣ Resource Sharing
- Threads same **address space** share karte hain
- Data sharing easy ho jaata hai
- Inter-thread communication fast hoti hai

---

### 3️⃣ Economy
- Thread creation **process creation se cheap** hoti hai
- Context switching threads ke beech:
  - Fast hota hai
  - Less overhead hota hai

---

### 4️⃣ Better Utilization of Multi-core CPU
- Multi-core systems me:
  - Alag-alag threads alag cores par run kar sakte hain
- Performance significantly improve hoti hai

---

## 🧠 Quick Comparison: Process vs Thread

| Feature | Process | Thread |
|-------|--------|-------|
| Weight | Heavy | Lightweight |
| Memory | Separate | Shared |
| Context Switch | Costly | Cheap |
| Communication | IPC needed | Shared memory |

---

## 🧠 One-Line Revision

**Concurrency allows multiple tasks to progress together, and threads enable efficient parallel execution inside a process**
