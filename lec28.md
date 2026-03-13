# Virtual Memory in OS | Page Fault

---

# 1. What is Virtual Memory?

Virtual Memory is a technique that allows a program to **run even if it is not completely loaded in RAM**. :contentReference[oaicite:0]{index=0}

Idea:

- Only **required pages** are loaded into RAM
- Remaining pages stay in **secondary storage (disk)**

The disk area used is called:

Swap Space / Swap Area

So effectively:

Virtual Memory = RAM + Swap Space


To the user it looks like **entire program is in RAM**, even though some parts are on disk.

---

# 2. Main Advantage

Programs can be **larger than physical memory (RAM)**. :contentReference[oaicite:1]{index=1}

Other benefits:

- Higher **multiprogramming**
- Better **CPU utilization**
- More processes can run simultaneously

---

# 3. Demand Paging

Demand Paging is the **most common implementation of Virtual Memory**.

Idea:

- Pages are loaded **only when needed**

Instead of loading the entire process:

Load only required pages


Pages that are **least used** may stay on disk.

---

# 4. Lazy Swapper vs Pager

**Lazy Swapper**

- Never loads a page until it is required

Technically:
Swapper → swaps entire process
Pager → swaps individual pages


Modern systems use **Pager**.

---

# 5. Valid / Invalid Bit

Each page table entry contains a **valid-invalid bit**.

1 → Page is in memory
0 → Page is on disk or invalid


Used to check whether page exists in RAM or not. :contentReference[oaicite:2]{index=2}

---

# 6. What is Page Fault?

A **Page Fault** occurs when:

CPU tries to access a page
but that page is not present in RAM


Hardware detects **invalid bit = 0** and triggers a **trap to OS**. :contentReference[oaicite:3]{index=3}

---

# 7. Steps to Handle Page Fault

1. CPU requests page
2. Hardware checks page table
3. If page not present → **page fault interrupt**
4. OS checks if request is valid
5. OS finds **free frame in RAM**
6. Required page is loaded from **disk to RAM**
7. Page table updated
8. Instruction restarted

Now process continues normally. :contentReference[oaicite:4]{index=4}

---

# 8. Pure Demand Paging

In extreme case:

Process starts with no pages in RAM

Pages are loaded **only when referenced**.

This is called:

Pure Demand Paging


---

# 9. Advantages of Virtual Memory

✔ Run programs larger than RAM  
✔ Increase multiprogramming  
✔ Better CPU utilization  

---

# 10. Disadvantages

❌ Disk access is slow  
❌ System may become slow  
❌ **Thrashing** may occur

---

# One-Line Revision

Virtual memory allows programs to run larger than RAM by loading pages **only when needed**, and a **page fault occurs when a required page is not present in memory**.
