# 🖥️ Operating System – Lecture 2 Notes

## 🤔 Goals of Operating System

Operating System ka main aim hota hai system resources ko **efficient, fair aur safe** way me use karna.

### ✅ Main Goals
- **Maximum CPU Utilization**  
  CPU zyada se zyada time busy rahe, idle na baithe.

- **Fair Resource Allocation**  
  Koi ek process saare resources occupy na kare.

- **Avoid Process Starvation**  
  Starvation ka matlab hai koi process hamesha wait hi karta rahe.  
  OS ka goal hota hai starvation ko avoid karna.

- **High Priority Execution**  
  Important task ko pehle execute karna.  
  Example:  
  Agar tum game khel rahe ho aur pen-drive insert hoti hai, to OS us pen-drive ko high priority dekar scan karta hai.

- **Fast Response Time**  
  User ke actions ka jaldi response milna chahiye.

- **High Throughput**  
  Ek unit time me zyada se zyada processes complete honi chahiye.

---

## 🧩 Types of Operating System

---

## 1️⃣ Single Process Operating System

### Features
- Sirf **ek hi process** memory me hota hai.
- Multitasking supported nahi.
- CPU ya to busy hota hai ya poora idle.

### Drawbacks
- CPU utilization low hota hai.
- Agar process I/O pe jaye to CPU waste hota hai.
- Modern OS goals follow nahi karta.

### Example
- MS-DOS

---

## 2️⃣ Batch Processing Operating System

### Working
- Jobs **Punch Cards** ke form me aati thi.
- **Operator** jobs ko collect karke similar jobs ke batches banata tha.
- Har batch sequentially CPU ko diya jata tha.
- Ek job complete hone ke baad next job start hoti thi.

### Problems
- User interaction nahi hota.
- Response time bahut zyada hota hai.
- I/O ke time CPU idle rehta hai.
- Starvation possible hai.

### Example
- Atlas

---

## 3️⃣ Multiprogramming Operating System

### Core Idea
- **Single CPU**
- Memory me multiple jobs loaded rehte hain.
- Ek **Ready Queue** maintain hoti hai.

- | j1 | j2 | j3 | j4 |

### Working
- CPU J1 execute karta hai.
- Agar J1 ko I/O operation chahiye:
  - J1 pause ho jata hai
  - CPU turant J2 ko execute karta hai
- Isse CPU idle nahi hota.

### Context Switching
- Current running process ka state save hota hai:
  - Program Counter
  - CPU Registers
  - Process State
- Ye sab store hota hai **PCB (Process Control Block)** me.

### Example
- THE (Technische Hogeschool Eindhoven)

---

## 4️⃣ Multitasking Operating System (Time Sharing OS)

### Features
- **Single CPU**
- Multiple tasks ek saath chalte hue lagte hain.
- **Time Quantum / Time Slice** use hota hai.

### Working
- Har process ko CPU ka fixed time milta hai.
- Time quantum expire hone par next process execute hota hai.
- Rapid context switching se multitasking possible hoti hai.

### Example
- CTSS (Compatible Time Sharing System)

---

## 5️⃣ Multiprocessing Operating System

### Features
- **Multiple CPUs / Cores**
- Processes actual parallel execute hote hain.
- High performance and reliability.

### Advantages
- Better throughput
- Faster execution
- Ek CPU fail ho jaye to system still kaam karta hai

### Example
- Windows
- Linux
- macOS

---

## 6️⃣ Distributed Operating System

### Definition
- Multiple **loosely coupled autonomous systems**
- Network ke through connected
- User ko ek single system jaisa feel hota hai

### Characteristics
- Resource sharing
- Load balancing
- Fault tolerance
- Scalability

### Examples
- Amoeba
- Plan 9
- Chorus
- Solaris
- AWS (conceptually distributed)

---

## 7️⃣ Real Time Operating System (RTOS)

### Definition
- Jaha **time constraint** sabse important hoti hai.
- Deadline miss hui to system failure ho sakta hai.

### Types
- **Hard RTOS**  
  Deadline miss = system failure  
  Example: ATC, missile systems

- **Soft RTOS**  
  Deadline miss thoda acceptable hota hai  
  Example: multimedia systems

### Use Cases
- Air Traffic Control
- Medical systems
- Industrial automation

### Examples
- QNX
- VxWorks
- FreeRTOS

---

## 🧠 Quick Comparison Table

| OS Type | CPU | Key Feature |
|------|----|------------|
| Single Process | 1 | One job at a time |
| Batch OS | 1 | Batch execution |
| Multiprogramming | 1 | CPU idle time reduced |
| Multitasking | 1 | Time sharing |
| Multiprocessing | ≥1 | Parallel execution |
| Distributed OS | Many | Network based |
| RTOS | Any | Strict timing |
