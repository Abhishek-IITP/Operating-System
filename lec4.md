# 🧩 Components of Operating System

Operating System mainly **do parts** me divided hota hai:
- **User Space**
- **Kernel Space**

---

## 👤 User Space

### What is User Space?
- Yaha **user applications** run karti hain
- **Direct hardware access nahi hota**
- Safe & convenient environment hota hai users ke liye
- Kernel ke through hardware se interact karta hai

### Examples
- **GUI Applications** → Browser, Media Player, Games
- **CLI Applications** → Terminal, PowerShell, Bash

### Important Point
> User space applications directly CPU, RAM, Disk ko access nahi kar sakti.  
> Har request kernel ke paas jaati hai.

---

## 🧠 Kernel

### What is Kernel?
- Kernel OS ka **heart / core** hota hai
- Hardware ke saath **direct interaction** karta hai
- System boot hone par **kernel sabse pehle load hota hai**
- Kernel **privileged mode (Kernel Mode)** me run karta hai

---

## 🧱 OS Architecture (Layered Diagram)

+----------------------+
| User Space |
| (Apps, GUI, CLI) |
+----------------------+
↑ ↓ (System Calls)
+----------------------+
| Kernel |
| (Core OS Services) |
+----------------------+
↑ ↓
+----------------------+
| Hardware |
| (CPU, RAM, Disk) |
+----------------------


> User Space + Kernel Space = **Operating System**

---

## ⚙️ Functions of Kernel


### 1️⃣ Process Management
- Process create & terminate karna
- Process scheduling (CPU kisko milega)
- Thread management
- Process synchronization
- Inter-Process Communication (IPC)

---

### 2️⃣ Memory Management
- Memory allocate & deallocate karna
- Free space management
- Virtual memory handle karna
- Paging & segmentation

---

### 3️⃣ File Management
- File create / delete
- File read / write
- Directory management
- File permissions

---

### 4️⃣ I/O Device Management
- All I/O devices ko control karna
- Device drivers ke through communication

#### 🔁 Spooling
- Jab **two devices ki speed different** ho
- Multiple jobs ek hi device ko use karte hain

**Examples**
- Printer spooling
- Mail spooling

#### 🔄 Buffering
- **Single job ke andar** speed mismatch handle karta hai

**Example**
- YouTube video buffering

#### 🗃️ Caching
- Frequently used data ko fast memory me store karna

**Examples**
- CPU cache
- Memory cache
- Web cache

---

## ⚡ Software Interrupt (System Call)

### What is Software Interrupt?
- User Mode se Kernel Mode me jaane ka **legal & safe way**
- Jab user program ko kernel service chahiye hoti hai

### Examples
- File open karna
- Keyboard input lena
- Memory allocate karna

### Flow

User Program

↓

System Call (Software Interrupt)

↓

Kernel Mode Execution

↓

Result back to User Program

> Software interrupt security ensure karta hai, taaki user directly kernel ko damage na kar sake.




## Types Of Kernel

## 1️⃣ Monolithic Kernel

- Saari OS services **kernel space ke andar**
- File system, memory, process, I/O sab ek jagah

### Mode Switching
- User Mode ↔ Kernel Mode
- Switching **software interrupt** se hoti hai

### Advantages:
- Fast communication btw different components of kernels

### Disadvantages:
- Kernel Bulky
- Less reliable becasue Ek bug poore system ko crash kar sakta hai
- Memory req to run is high.

### Examples
- Linux
- Unix
- MS-DOS

>User Space
>
>↓
>
>+--------------------------------+
>
>| File | Memory | Process | I/O |
>
>| Monolithic Kernel |
>
>+--------------------------------+
>
>↓
>
>Hardware

---

## 2️⃣ Microkernel

- user space  contains = File Management & I/O
- Kernel space contains = Memory(RAM) & Process Management(CPU).

### Advantages:
- Kernel lightweight hota hai
- More reliable & stable

### Disadvantages:
- User ↔ Kernel communication overhead
- Performance thodi slow hoti hai


### Examples
- L4 Linux
- Symbian OS


>User Space
>
>+-----------------------------+
>| File System | I/O Services |
>+-----------------------------+
>
>↓ IPC
>
>+-----------------------------+
>| Microkernel (CPU, RAM) |
>+-----------------------------+
>
>↓
>
>Hardware

---

## 3️⃣ Hybrid Kernel

- Monolithic + Microkernel ka combination

### Structure
- File management → User Mode
- Process, Memory, I/O → Kernel Mode

### Advantages
- Microkernel se fast
- Monolithic se zyada stable

### Examples
- Windows
- macOS 

---


## 4️⃣ Nano Kernel / Exokernel

### Nano Kernel
- Extremely small kernel
- Sirf basic tasks handle karta hai:
  - Interrupt handling
  - Context switching
  - Low-level CPU control

### Exokernel
- Kernel sirf **hardware access** deta hai
- Resource management applications khud karti hain

### Pros
- High performance
- Maximum flexibility

### Cons
- Complex design
- General purpose OS me rarely used


## Important Question 

1. who User Mode & Kernel Mode communicate to each other??

#### ans:- 
- **System Calls**
- Implemented using **Software Interrupts**

---

InterProcess-Communication(IPC) 
- Two Processes executing independently, having independent memory space(Memory Protection), but some may need to communicate to work.

### IPC Types
1. **Shared Memory**
   - Multiple processes ek common memory share karte hain
   - Fast communication

2. **Message Passing**
   - Processes messages ke through baat karte hain
   - Logical pipe / queue use hoti h





## 🔑 Key Points
- User space has no hardware access
- Kernel controls hardware
- Software interrupt is the bridge
- Kernel design performance & stability decide karta hai







