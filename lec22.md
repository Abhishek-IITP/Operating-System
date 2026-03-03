# 🛡 Deadlock Avoidance | Deadlock Detection and Recovery

---

# 🔷 Deadlock Avoidance

## 📌 Basic Idea

- OS ko **advance me pata hona chahiye**:
  - Har process ko apne lifetime me
  - Maximum kitne resources chahiye honge

kernel ko pata hona chahiye:

1. Total number of processes  
2. Resource need of each process  
3. Currently allocated resources  
4. Maximum resources required  

� OS resources ko aise allocate karta hai ki system **Safe State** me rahe

---

## ✅ Safe State

system safe state me tab hota hai jab:

> There exists a **Safe Sequence**

### Safe Sequence

ek aisa order of processes jisme:
- Har process ko required resources mil jaate hain
- Aur sab processes complete ho sakte hain
- Without deadlock

---

# 🏦 Banker’s Algorithm

## 📌 Why Called Banker?

- Banker kabhi bhi loan aise nahi deta
- Jisse bank bankrupt ho jaye
- Same logic:
  - OS resources tabhi allocate karega
  - Jab system safe state me rahe

---

## 🧠 Data Structures Used

1. **Available**
   - Kitne resources available hain

2. **Max**
   - Har process ko maximum kitne resources chahiye

3. **Allocation**
   - Currently kitne resources allocated hain

4. **Need**
   - Remaining resource need

Need = Max – Allocation


---

# 📊 Example Table

Assume:

- 3 resource types: A, B, C
- 5 processes: P0–P4

---

## 🔹 Allocation Table

| Process | A | B | C |
|----------|---|---|---|
| P0 | 0 | 1 | 0 |
| P1 | 2 | 0 | 0 |
| P2 | 3 | 0 | 2 |
| P3 | 2 | 1 | 1 |
| P4 | 0 | 0 | 2 |

---

## 🔹 Max Table

| Process | A | B | C |
|----------|---|---|---|
| P0 | 7 | 5 | 3 |
| P1 | 3 | 2 | 2 |
| P2 | 9 | 0 | 2 |
| P3 | 2 | 2 | 2 |
| P4 | 4 | 3 | 3 |

---

## 🔹 Need Table (Max - Allocation)

| Process | A | B | C |
|----------|---|---|---|
| P0 | 7 | 4 | 3 |
| P1 | 1 | 2 | 2 |
| P2 | 6 | 0 | 0 |
| P3 | 0 | 1 | 1 |
| P4 | 4 | 3 | 1 |

---

## 🔹 Available

Available = (3, 3, 2)


---

## 🔄 Safe Sequence Check

1. Find process whose Need ≤ Available  
2. Allocate → Process finishes  
3. Release its Allocation  
4. Update Available  
5. Repeat  

If all processes complete → Safe State  
If stuck → Unsafe State

---

# 🔎 Deadlock Detection

Deadlock Avoidance ≠ Detection

Avoidance:
- Never allow unsafe state

Detection:
- Allow system to enter deadlock
- Detect it
- Then recover

---

## 1️⃣ Single Instance of Each Resource

Use **Wait-For Graph (WFG)**

### Wait-For Graph Concept

- Nodes = Processes
- Edge P1 → P2:
  - P1 waiting for resource held by P2

---

### Deadlock Condition

If WFG me **cycle exist karta hai**
→ Deadlock present

---

### Example Diagram

P1 → P2
P2 → P3
P3 → P1


👉 Circular wait → Deadlock

---

## 2️⃣ Multiple Instances of Resources

Use:
- Banker’s style detection algorithm

### Logic

- If safe sequence exists → No Deadlock
- If no safe sequence possible → Deadlock detected

Algorithm run periodically

---

# ♻ Recovery from Deadlock

---

## 1️⃣ Process Termination

### Option A:
- Abort all deadlocked processes

### Option B:
- Abort one process at a time
- Until cycle removed

### Issues:
- Data loss
- Rollback cost
- Performance impact

---

## 2️⃣ Resource Preemption

- Some resources forcibly taken from process
- Given to other process
- Break circular wait

### Problems:
- Which process to preempt?
- Rollback mechanism required
- Starvation possible

---

# 🧠 Summary Comparison

| Technique | Idea | Advantage | Disadvantage |
|------------|------|------------|--------------|
| Prevention | Break condition | Simple | Low utilization |
| Avoidance | Maintain safe state | No deadlock | Expensive |
| Detection | Detect after occurs | Better utilization | Recovery cost |
| Ostrich | Ignore | Simple | Risky |

---

# 🧠 One-Line Revision

**Deadlock avoidance uses Banker’s algorithm to maintain safe state, detection identifies deadlock using graph or allocation checks, and recovery resolves it via termination or preemption**