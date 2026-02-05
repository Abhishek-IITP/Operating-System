# 🚦 What is Convoy Effect?

---

## ⏱️ Process Scheduling (Short Explanation)

- **Process Scheduling** is the mechanism by which the OS decides:
  - Kaunsa process CPU use karega
  - Kab aur kitni der ke liye

- Scheduler ka main goal hota hai:
  - CPU ko idle na rehne dena
  - Processes ko efficiently execute karna

---

## 🧠 Types of Scheduling Algorithms

---

## 1️⃣ Non-Preemptive Scheduling

- Ek baar dispatcher ne CPU kisi process ko de diya  
- Process **CPU tab tak hold karega** jab tak:
  - Process terminate ho jaaye **OR**
  - Process I/O ke liye chali jaaye  

### Characteristics
- Time sharing / time quantum **nahi hota**
- Long process CPU ko block kar sakta hai
- **Process starvation zyada hota hai**

---

## 2️⃣ Preemptive Scheduling

- Process ko CPU **time quantum** ke basis par milta hai
- CPU release ho sakta hai:
  - Process terminate ho
  - I/O ke liye jaye
  - **Time quantum expire ho jaaye**

### Characteristics
- Time sharing supported
- CPU utilization zyada hoti hai
- **Overhead zyada hota hai** (due to context switching)

---

## 🎯 Goals of CPU Scheduling

1. **Maximum CPU Utilization**
2. **Minimum Turnaround Time (TAT)**  
   - `TAT = Completion Time (CT) – Arrival Time (AT)`
3. **Minimum Waiting Time (WT)**  
   - `WT = TAT – Burst Time (BT)`
4. **Minimum Response Time**  
   - Time between first arrival in ready queue and first CPU allocation
5. **Maximum Throughput**  
   - Number of processes completed per unit time




## 🧮 Scheduling Jargons (Very Important)

---

### ⏱️ AT – Arrival Time
- Wo time jab **process ready queue me enter karta hai**
- Process execution ke liye OS ke paas aata hai

**Example:**  
Agar P1 time `0` par ready queue me aaya  
→ **AT = 0**

---

### 🔥 BT – Burst Time
- Wo **actual CPU time** jo process ko complete hone ke liye chahiye
- Process jitna time CPU pe run karega

**Example:**  
Agar P1 ko CPU par 5 units ka time chahiye  
→ **BT = 5**

---

### 🏁 CT – Completion Time
- Wo time jab **process completely finish** ho jaata hai
- Last instruction execute hone ka time

**Example:**  
Agar P1 time `10` par finish hua  
→ **CT = 10**

---

### 🔁 TAT – Turnaround Time
- Total time jo process ne system me spend kiya  
- From **arrival** to **completion**

---

## 🥇 FCFS (First Come First Serve)

- **Non-preemptive scheduling algorithm**
- Process ko CPU **arrival order** me milta hai
- Simple but inefficient in many cases

---

## 🚚 Convoy Effect (Important Concept)

### What is Convoy Effect?
- Jab **ek long burst time process** CPU ko pakad ke baith jaata hai
- Uske peeche **bahut saare short processes wait** karte rehte hain

👉 Is situation ko **Convoy Effect** kehte hain

---

### Definition (Exam-Friendly)
> Convoy Effect is a situation where many short processes are blocked by a single long process holding the CPU for a long time, leading to poor CPU utilization and high waiting time.

---

## 📊 Example to Understand Convoy Effect

### Process Table

| Process | Arrival Time (AT) | Burst Time (BT) |
|--------|------------------|----------------|
| P1 | 0 | 24 |
| P2 | 0 | 3 |
| P3 | 0 | 3 |

---

### Gantt Chart (FCFS)

| P1 | P2 | P3 |
 24   27   30
---

### Calculation Table

| Process | AT | BT | CT | TAT = CT-AT | WT = TAT-BT |
|--------|----|----|----|-------------|-------------|
| P1 | 0 | 24 | 24 | 24 | 0 |
| P2 | 0 | 3 | 27 | 27 | 24 |
| P3 | 0 | 3 | 30 | 30 | 27 |

---

### Observations
- P2 aur P3 ka burst time **bahut chhota** hai
- Lekin unhe **bahut zyada wait** karna pada
- Average waiting time **bahut high** ho gaya

👉 Yehi **Convoy Effect** hai

---

## ❌ Problems Caused by Convoy Effect

- High waiting time
- Poor CPU utilization
- Low throughput
- Bad user experience

---

## ✅ How to Reduce Convoy Effect?

- Use **Preemptive scheduling**
- Use algorithms like:
  - Shortest Job First (SJF)
  - Round Robin (RR)
- Introduce **time quantum**

---

## 🧠 One-Line Revision

**Convoy Effect occurs in FCFS when one long process delays many short processes, increasing average waiting time and reducing performance**
