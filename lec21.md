# 🔒 What is Deadlock | Necessary Conditions | Handling Methods

---

## 📌 What is Deadlock?

In a **multiprogramming environment**, multiple processes compete for a **finite number of resources**.

Deadlock occurs when:

- A process requests a resource
- The resource is already allocated to another process
- The requesting process enters waiting state
- But that resource will **never become available**

👉 Because the process holding it is also waiting for some other resource.

### Definition

> Deadlock is a situation where two or more processes are waiting indefinitely for resources held by each other.

---

## 🧩 How a Process Uses a Resource?

A process typically follows:

1. **Request** the resource  
2. **Use** the resource  
3. **Release** the resource  

Deadlock happens when processes get stuck between request and release.

---

# ⚠️ Necessary Conditions for Deadlock (Coffman Conditions)

All 4 conditions must hold simultaneously:

---

## 1️⃣ Mutual Exclusion

- Resource can be used by **only one process at a time**
- Non-shareable resource

Example:
- Printer
- Mutex lock

---

## 2️⃣ Hold and Wait

- Process is holding at least one resource
- And waiting for additional resources

---

## 3️⃣ No Preemption

- Resource cannot be forcibly taken away
- Process must release it voluntarily

---

## 4️⃣ Circular Wait

- Circular chain of processes exists:
  
P0 → waiting for resource held by P1
P1 → waiting for resource held by P2
P2 → waiting for resource held by P0


👉 Circular dependency forms

---

# 📊 Resource Allocation Graph (RAG)

Used to represent:

- Process–Resource relationships
- Check deadlock visually

---

## 🔷 Components

### Vertices

1. Process Vertex → Circle (P)
2. Resource Vertex → Box (R)

---

### Edges

1. **Request Edge**  
   P → R (Process requesting resource)

2. **Assignment Edge**  
   R → P (Resource allocated to process)

---

## 🔁 Deadlock Diagram (Example)

```
 [R1]           [R2]
 
  |             |
 
  v             v
 
 (P1)  ---->   (P2)
    
    ^           |

    |___________|
```


Explanation:

- P1 holds R1 and waits for R2
- P2 holds R2 and waits for R1
- Circular wait formed → Deadlock

---

# 🛠 Methods to Handle Deadlock

---

## 1️⃣ Deadlock Prevention / Avoidance

- Ensure at least one necessary condition never holds

---

## 2️⃣ Detection and Recovery

- Allow system to enter deadlock
- Detect it
- Recover from it

---

## 3️⃣ Ostrich Algorithm

- Ignore deadlock completely
- OS assumes:
  - Deadlock rare hai
- Application programmer handle kare

Used in:
- UNIX
- Windows

---

# 🔐 Deadlock Prevention Techniques

---

## 1️⃣ Prevent Mutual Exclusion

- Make resources shareable wherever possible

Example:
- Read-only files → shareable

⚠️ But:
- Some resources inherently non-shareable
- So full elimination not possible

---

## 2️⃣ Prevent Hold and Wait

Guarantee:

- Process never holds resource while requesting another

### Protocol A:
- Process must request **all resources at once**
- Before execution begins

### Protocol B:
- Process can request resources only when:
  - It holds **none**

⚠️ Drawback:
- Low resource utilization

---

## 3️⃣ Prevent No Preemption

If process holds some resources and requests new one:

- If new resource unavailable:
  - Preempt currently held resources
  - Return them to system
  - Process restarts later

⚠️ Risk:
- Live lock possible

---

## 4️⃣ Prevent Circular Wait

Impose strict ordering on resources.

Example:

- Suppose R1 and R2 required
- Rule: Always lock R1 first, then R2

Correct Order:
P1 → R1 → R2
P2 → R1 → R2


👉 Circular wait impossible

---

# 🧠 Summary Table

| Condition | Meaning | Prevention Idea |
|------------|---------|----------------|
| Mutual Exclusion | Resource not shareable | Make shareable |
| Hold & Wait | Holding + Waiting | Request all at once |
| No Preemption | Cannot force release | Allow preemption |
| Circular Wait | Circular dependency | Resource ordering |

---

# 🧠 One-Line Revision

**Deadlock occurs when processes wait indefinitely due to circular resource dependency, and it can be handled by prevention, avoidance, detection, or ignoring it**