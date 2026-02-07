
# 🧮 Shortest Job First (SJF) | Priority Scheduling | Round Robin (RR)

---

## 🥇 Shortest Job First (SJF) Scheduling

### 📌 Idea
- **Jis process ka Burst Time (BT) sabse kam hota hai**, usse CPU milta hai
- Goal: **Average Waiting Time minimize** karna

---

## 🔹 SJF (Non-Preemptive)

- Ek baar CPU mil gaya → process tab tak run karega jab tak:
  - Process complete ho jaaye **OR**
  - I/O ke liye chala jaaye

---

### 📊 Process Table

| Process | AT | BT | CT | TAT | WT |
|--------|----|----|----|-----|----|
| P1 | 0 | 8 | 8 | 8 | 0 |
| P2 | 1 | 4 | 12 | 11 | 7 |
| P3 | 2 | 9 | 26 | 24 | 15 |
| P4 | 3 | 5 | 17 | 14 | 9 |

---

### ⏱️ Gantt Chart (Non-Preemptive SJF)
| P1 | P2 | P4 | P3 |
0 8 12 17 26

- **P4 CPU pe P3 se pehle aaya**  
  Kyunki **BT(P4)=5 < BT(P3)=9**

---

### 📈 Average Waiting Time
Average WT = (0 + 7 + 15 + 9) / 4 = 7.75


---

### ❌ Drawbacks of SJF (Non-Preemptive)

- **Convoy Effect ka victim**
- **CPU Starvation possible**

#### Kyu Convoy Effect hota hai?
- Agar pehle aaya process ka BT bahut zyada ho  
- Toh baaki short jobs **wait hi karte rehte hain**

---

## 🔹 SJF (Pre-emptive)  
(Also called **Shortest Remaining Time First – SRTF**)

- Har **1 time unit** ke baad check hota hai:
  - Kya koi aur process hai jiska **remaining BT kam** hai?

---

### 📊 Process Table (Pre-emptive)

| Process | AT | BT | CT | TAT | WT |
|--------|----|----|----|-----|----|
| P1 | 0 | 8 | 17 | 17 | 9 |
| P2 | 1 | 4 | 5 | 4 | 0 |
| P3 | 2 | 9 | 26 | 24 | 15 |
| P4 | 3 | 5 | 10 | 7 | 2 |

---

### ⏱️ Gantt Chart (Pre-emptive SJF)
| P1 | P2 | P4 | P1 | P3 |
0 1 5 10 17 26

---

### 📈 Average Waiting Time
Average WT = (9 + 0 + 15 + 2) / 4 = 6.5



---

### ❌ Major Drawback of SJF (Both Types)

> **Exact Burst Time pehle se jaan-na practically impossible hai**

---

## 🥈 Priority Scheduling

### 📌 Idea
- Har process ko **priority assign** hoti hai
- **Higher priority → pehle CPU**

---

## 🔹 Non-Preemptive Priority Scheduling

- Ek baar CPU mil gaya → process complete hone tak run karta hai

### ❌ Drawback
- **Low priority processes peeche chhoot jaate hain**
- Starvation possible

---

## 🔹 Pre-emptive Priority Scheduling

- Agar koi **higher priority process** aa jaaye
- Toh running process **pre-empt** ho jaata hai

---

### ❌ Biggest Drawback

> **Indefinite Waiting / Extreme Starvation**

---

## 📜 Real Incident (Rumor but Famous)

### IBM 7094 – MIT (1967–1973)

- 1967 me jobs submit ki gayi
- Low-priority jobs **kabhi execute hi nahi hui**
- 1973 me pata chala:
  - Low-priority tasks **saalon se wait kar rahi thi**

👉 Ye **Priority Scheduling starvation** ka real-life example hai

---

## ✅ Solution to Indefinite Waiting

### 🧓 Ageing

- Waiting ke saath-saath:
  - Low priority job ki **priority gradually increase** kar do

👉 Starvation kam hota hai  
❌ Lekin **Convoy Effect poori tarah nahi jaata**

---

## 🥉 Round Robin (RR) Scheduling

### 📌 Idea
- Har process ko CPU **fixed Time Quantum (TQ)** ke liye milta hai
- FCFS ka **Pre-emptive version**

---

### 🔹 Characteristics

- **Very low response time**
- **Starvation almost nahi hoti**
- Convoy effect ka impact bahut kam
- Most popular scheduling algorithm
- Time-sharing systems ke liye designed
- Easy to implement
- Used in **Multitasking OS**

---

### 📐 Criteria
- **Arrival Time (AT)**
- **Time Quantum (TQ)**
- Burst Time (BT) indirectly handled

---

### ⏱️ Example Gantt Chart (RR)

Assume:
- TQ = 2

| P1 | P2 | P3 | P4 | P1 | P3 | P4 | ...



- Har process ko **fair CPU share** milta hai

---

### ⚠️ Overhead in Round Robin

- Overhead depends on **Time Quantum**

| Time Quantum | Effect |
|-------------|-------|
| Too small | Too many context switches (high overhead) |
| Too large | RR ≈ FCFS (poor response time) |

👉 **Optimal TQ choose karna important hai**

---

## 🧠 Final Comparison (One Look)

| Algorithm | Pre-emptive | Starvation | Convoy Effect |
|---------|------------|------------|---------------|
| FCFS | ❌ | ❌ | ✅ |
| SJF | ❌ / ✅ | ✅ | ✅ |
| Priority | ❌ / ✅ | ❌❌ | ✅ |
| Round Robin | ✅ | ❌ | ❌ |

---

## 🧠 One-Line Revision

**SJF minimizes average waiting time but suffers from starvation, Priority scheduling causes indefinite waiting, and Round Robin balances fairness with low response time**
