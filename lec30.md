# Thrashing in Operating System

---

# 1. What is Thrashing?

Thrashing occurs when a process **does not have enough frames in RAM** to hold the pages it actively needs.

So the system repeatedly:

1. Page fault occurs
2. OS replaces a page
3. That replaced page is needed again immediately
4. Another page fault occurs

This continuous page swapping is called:

Thrashing


A system is thrashing when:


It spends more time handling page faults than executing processes


---

# 2. Why Thrashing Happens

Main reason:


Too few frames allocated to processes


Steps causing thrashing:

1. Initially CPU utilization is low
2. OS increases **degree of multiprogramming**
3. More processes compete for memory
4. Frames per process decrease
5. Page faults increase
6. CPU utilization drops sharply

This creates a **thrashing cycle**.

According to the diagram on page 1 of the lecture notes, CPU utilization first increases with multiprogramming but then **suddenly drops when thrashing begins**. :contentReference[oaicite:0]{index=0}

---

# 3. Global Page Replacement Problem

When **global page replacement algorithm** is used:

- A process may replace frames belonging to other processes
- Those processes soon need those pages again
- Page faults increase rapidly

This leads to thrashing.

---

# 4. How to Handle Thrashing

Two main techniques:

Working Set Model

Page Fault Frequency


---

# 5. Working Set Model

Based on **Locality of Reference**.

Idea:


Allocate enough frames to a process
to hold its current working pages


Working set = pages currently being used.

If frames allocated < working set size:


Process will thrash


So OS ensures **each process gets enough frames**. :contentReference[oaicite:1]{index=1}

---

# 6. Page Fault Frequency (PFF)

Idea:

Control the **rate of page faults**.

Define limits:

Upper limit → too many faults
Lower limit → too few faults


Rules:

- If **page fault rate too high**
  → allocate more frames

- If **page fault rate too low**
  → remove some frames

This keeps system stable and avoids thrashing. :contentReference[oaicite:2]{index=2}

---

# 7. Summary

| Concept | Meaning |
|------|------|
| Thrashing | Excessive paging activity |
| Cause | Too few frames per process |
| Effect | CPU utilization drops |
| Solution | Working Set Model |
| Alternative | Page Fault Frequency |

---

# One-Line Revision

Thrashing occurs when a system spends **more time handling page faults than executing processes due to insufficient memory frames**.