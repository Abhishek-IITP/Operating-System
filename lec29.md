# Page Replacement Algorithms in OS

---

# 1. What is a Page Fault?

A **Page Fault** occurs when the CPU tries to access a page that is **not present in RAM**.

RAM generates an interrupt to OS.

OS then:

1. Finds the required page in **swap space (disk)**
2. Brings that page into RAM
3. Removes another page if memory is full

The time taken to complete this process is called:

Page Fault Service Time


---

# 2. Why Page Replacement Algorithms?

If RAM is full and a new page is needed:


Which page should be removed?


To decide this, OS uses **Page Replacement Algorithms**.

Goal:


Minimize the number of page faults

---

# 3. FIFO (First In First Out)

Idea:


Replace the oldest page in memory


Example:

Pages enter memory in order → remove the first one.

### Advantages

- Very simple
- Easy to implement

### Disadvantages

- May remove heavily used pages
- Poor performance sometimes

---

### Belady's Anomaly

Normally:

More frames → fewer page faults

But in FIFO sometimes:

More frames → MORE page faults

This strange behavior is called:

Belady's Anomaly


FIFO shows this anomaly.

---

# 4. Optimal Page Replacement

Idea:

Replace the page that **will not be used for the longest time in future**.

Steps:

1. Check future references
2. Find page used farthest in future
3. Replace that page

### Advantages

- **Minimum page faults possible**

### Disadvantages

- Impossible to implement in real OS
- Requires **future knowledge**

Similar idea to **SJF scheduling**.

---

# 5. Least Recently Used (LRU)

Idea:

Replace the page that has not been used for the longest time


Assumption:


Past behavior predicts future behavior


If a page was not used recently, it is likely **not needed soon**.

---

# 6. How to Implement LRU?

Two main methods:

---

## Method 1: Counters

Each page table entry stores a **time stamp**.

Steps:

1. Every memory reference updates the counter
2. Page with **smallest time value** is the least recently used
3. Replace that page

---

## Method 2: Stack (Most Popular Concept)

Maintain a **stack of page numbers**.

Rules:

1. When a page is referenced → move it to **top**
2. Top → **Most Recently Used**
3. Bottom → **Least Recently Used**

Example:
Top → Most Recently Used
Bottom → Least Recently Used


To efficiently remove elements from middle:


Use Doubly Linked List


---

# 7. Counting-Based Algorithms

These algorithms use **reference counters**.

---

## LFU (Least Frequently Used)

Idea:

Replace the page with **smallest reference count**.

Assumption:

Frequently used pages are important


---

## MFU (Most Frequently Used)

Idea:

Replace page with **largest reference count**.

Assumption:


Page with small count may be new


---

### Note

LFU and MFU are **rarely used in real systems**.

---

# Algorithm Comparison

| Algorithm | Idea | Advantage | Disadvantage |
|----------|------|----------|-------------|
| FIFO | Remove oldest page | Simple | Belady anomaly |
| Optimal | Replace farthest future page | Minimum faults | Impossible to implement |
| LRU | Replace least recently used | Good performance | Costly tracking |
| LFU | Replace least used page | Uses frequency | Rarely used |
| MFU | Replace most used page | Alternative logic | Rarely used |

---

# One-Line Revision

Page replacement algorithms decide **which page to remove from RAM during a page fault**, and the most practical algorithm used in theory is **LRU**.
