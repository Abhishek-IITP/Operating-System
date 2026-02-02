# ⚙️ How Operating System Creates a Process?

---

## 🔹 What is a Process? (What & Why)

### What is a Process?
- Source code (`.c / .cpp`)  
  → **Compiler**  
  → **Executable file**  
  → **Execution starts**

👉 **Program under execution is called a Process**

> Program = Passive (stored on disk)  
> Process = Active (running in memory)

---

### Why do we need a Process?
- User ka kaam (task) execute karne ke liye
- OS resources (CPU, Memory, I/O) manage karne ke liye
- Multiple programs ko safely run karane ke liye

---

## 🛠️ How OS Creates a Process (Step-by-Step)

---

### Step 1: Load Program into Memory
- OS program code (**text section**) ko memory me load karta hai
- Static & global data bhi load hota hai
- Ye data **initialization** ke kaam aata hai

---

### Step 2: Allocate Runtime Stack
- Stack memory allocate hoti hai
- Stack use hota hai:
  - Local variables
  - Function arguments
  - Return values

---

### Step 3: Allocate Heap
- Heap memory allocate hoti hai
- Heap use hota hai:
  - Dynamic memory allocation (`malloc`, `new`)

---

### Step 4: Set up I/O Resources

- OS standard I/O handles set karta hai

#### In Unix/Linux:
- **stdin**  → Input  
- **stdout** → Output  
- **stderr** → Error  

Example:
```c
fprintf(stderr, "error occurred");
```

## 🛠️ Step 5: Handoff Control to `main()`

- Sab setup hone ke baad  
- OS CPU control **`main()` function** ko de deta hai  
- Yahin se **process execution officially start** hota hai  

---



## 🧠 Process Memory Architecture

```c
+---------------------------+
|           Stack           |  ← Grows downward
+---------------------------+
|                           |
|                           |
|                           |
|                           |
+---------------------------+
|            Heap           |  ← Grows upward
+---------------------------+
|            Data           |  (Global & Static variables)
+---------------------------+
|            Text           |  (Program Code)
+---------------------------+
```


---

## 🔁 Stack & Heap Relationship

- Initially **stack aur heap ek dusre se door** hote hain  
- Dono **opposite directions** me grow karte hain  

---

## ❌ Errors Explained (Simple Way)

### 🔥 Stack Overflow
- Jab stack continuously grow karta hai  
- Aur heap ke paas aa kar **touch** kar leta hai  

**Common reasons**
- Infinite recursion  
- Large local variables  

---

### ❌ Out of Memory (Heap Overflow)
- Jab heap grow karta hai  
- Aur stack ke paas aa kar **touch** kar leta hai  

**Common reasons**
- Memory leak  
- Too much dynamic allocation  

---

## ✅ How to Prevent These Errors

### Prevent Stack Overflow
- Infinite recursion avoid karo  
- Large arrays ko stack me nahi, **heap me allocate** karo  
- Proper base condition likho  

### Prevent Out of Memory
- Dynamically allocated memory free karo (`free`, `delete`)  
- Memory leaks avoid karo  
- Heap usage monitor karo  

---

## 📋 Attributes of a Process

- OS saare processes ko **Process Table** me maintain karta hai  
- Har process ka ek entry hota hai  
- Ye information store hoti hai **PCB (Process Control Block)** me  

---

## 🧾 Process Control Block (PCB)

```c
+----------------------------+
|        Process ID (PID)    | → Unique identifier
+----------------------------+
|        Program Counter     | → Next instruction address
+----------------------------+
|        Process State       | → New, Ready, Running, Waiting
+----------------------------+
|        Priority            |
+----------------------------+
|        CPU Registers       | → SP, BP, CR etc.
+----------------------------+
|        Open File List      |
+----------------------------+
|        Open Device List    |
+----------------------------+
```

---

## 🧠 Important Points (Exam Ready)

- Process = Program in execution  
- OS creates process in multiple steps  
- Stack & Heap are parts of process memory  
- PCB stores complete process information  
- Context switching uses PCB  

---

## 🧠 One-Line Revision

**OS creates a process by loading code, allocating memory, setting I/O, and transferring control to `main()`**

