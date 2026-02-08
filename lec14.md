
# 🧵 Multi-Level Queue Scheduling | MLFQ | CPU Scheduling Comparison

---

## 🧱 Multi-Level Queue Scheduling (MLQ)

### 📌 Basic Idea
- **Ready Queue ko multiple queues me divide** kiya jata hai
- Division usually **priority / process type** ke basis par hota hai
- Har process **permanently ek queue me assign** hota hai  
  👉 Inter-queue movement **allowed nahi hota** (Inflexible)

---

## 🧑‍💻 Types of Processes

### 1️⃣ System Processes
- OS ke dwara create kiye jaate hain
- System ko chalane ke liye required hote hain

**Example:**  
- Terminal  
- Device drivers  

---

### 2️⃣ Interactive / Foreground Processes
- User input required hota hai
- Fast response time chahiye

**Example:**  
- Browser  
- Text editor  

---

### 3️⃣ Batch / Background Processes
- User interaction nahi hota
- Long-running jobs

**Example:**  
- Backup jobs  
- Data processing tasks  

---

## 🧩 Multi-Level Queue Structure (Diagram)

+-------------------------------+
| System Process (SP) Queue | ← Highest Priority
| Scheduling: Round Robin |
+-------------------------------+
↓
+-------------------------------+
| Interactive Process (IP) Queue|
| Scheduling: Round Robin |
+-------------------------------+
↓
+-------------------------------+
| Batch Process (BP) Queue | ← Lowest Priority
| Scheduling: FCFS |
+-------------------------------+



> **Top to Bottom → Priority Decreases**

---

## ⚙️ Scheduling Rules (MLQ)

- Har queue ka **apna scheduling algorithm** hota hai  
- Example:
  - SP → Round Robin
  - IP → Round Robin
  - BP → FCFS

- **Strict priority scheduling** follow hota hai:
  - Jab tak upper queue empty nahi hoti
  - Lower queue ko CPU **nahi milta**

---

## ❌ Drawbacks of Multi-Level Queue Scheduling

- **Indefinite Waiting / Starvation**
- Lower priority queues ke processes:
  - Bahut zyada wait kar sakte hain
- Convoy Effect possible

👉 Isliye MLQ **inflexible & unfair** ho sakta hai

---

## 🔁 Multi-Level Feedback Queue Scheduling (MLFQ)

### 📌 Basic Idea
- Multiple queues present hoti hain (like MLQ)
- **Inter-queue movement allowed hota hai**
- Process ka priority **dynamic hota hai**

---

## 🧠 Key Concepts of MLFQ

- **CPU-bound processes** → Lower priority
- **I/O-bound / Interactive processes** → Higher priority
- Higher BT → Lower priority
- Lower BT → Higher priority
- **Ageing used** to prevent starvation

---

## 🧩 Configurable MLFQ Diagram (Generic Design)

+-------------------------------+
| Q0 (Highest Priority) |
| Scheduling: Round Robin (TQ=2)|
+-------------------------------+
↓ (Time Quantum Expire)
+-------------------------------+
| Q1 |
| Scheduling: Round Robin (TQ=4)|
+-------------------------------+
↓
+-------------------------------+
| Q2 (Lowest Priority) |
| Scheduling: FCFS |
+-------------------------------+


---

## 🔄 Movement Rules in MLFQ

### ⬇️ Demotion (Move Down)
- Agar process:
  - Apna full time quantum use kar leta hai
- Matlab process **CPU-bound** hai
- Usse **lower priority queue** me bhej diya jata hai

---

### ⬆️ Promotion (Move Up)
- Agar process:
  - I/O ke liye frequently block hota hai
  - Ya bahut time se wait kar raha hai
- Ageing ke through:
  - Priority increase kar di jati hai

---

## ⚙️ Design Parameters of MLFQ

1. **Number of Queues**
2. **Scheduling Algorithm of each Queue**
3. **Time Quantum of each Queue**
4. **Promotion Rule** (How process moves up)
5. **Demotion Rule** (How process moves down)
6. **Initial Queue** where new process enters

---

## ❓ Example: Where will Process P1 go?

- Agar **P1 new process** hai:
  - Usually **highest priority queue (Q0)** me aata hai

- Agar P1:
  - Full time quantum use karta hai → demoted
  - I/O frequently karta hai → stays / promoted

---

## ⚖️ MLQ vs MLFQ (Comparison)

| Feature | MLQ | MLFQ |
|------|----|------|
| No. of Queues | Multiple | Multiple |
| Inter-queue movement | ❌ No | ✅ Yes |
| Priority | Fixed | Dynamic |
| Starvation | High | Low (due to ageing) |
| Flexibility | Low | High |
| Complexity | Low | High |

---

## 🧠 CPU Scheduling Algorithms Comparison

| Algorithm | Pre-emptive | Starvation | Response Time | Complexity |
|--------|------------|------------|---------------|------------|
| FCFS | ❌ | ❌ | Poor | Very Low |
| SJF | ❌ / ✅ | ✅ | Good | Medium |
| Priority | ❌ / ✅ | ❌❌ | Medium | Medium |
| Round Robin | ✅ | ❌ | Very Good | Medium |
| MLQ | ❌ | ❌❌ | Good | Medium |
| MLFQ | ✅ | ❌ | Excellent | High |

---

## 🧠 One-Line Revision

**MLQ uses fixed priority queues causing starvation, while MLFQ dynamically adjusts priority using feedback to achieve fairness and responsiveness**
