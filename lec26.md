# Paging in OS | Non-Contiguous Memory Allocation

---

# 1. Why Paging is Needed

Problem with **Dynamic Partitioning** → External Fragmentation.

Example:

Free memory blocks:
1KB + 1KB

Process needs:
2KB

Even though total memory = 2KB, process **cannot be loaded** because memory is **not contiguous**.

Solution → **Paging**

---

# 2. What is Paging?

Paging is a **memory management technique** that allows a process to be stored in **non-contiguous memory blocks**. :contentReference[oaicite:1]{index=1}

Idea:

- Logical memory → divided into **Pages**
- Physical memory → divided into **Frames**

Important rule:

Page Size = Frame Size


Example:


Logical Memory (Process)
Page 0
Page 1
Page 2
Page 3

Physical Memory
Frame 0
Frame 1
Frame 2
Frame 3


Pages can be stored in **any free frame**.

This removes **external fragmentation**.

---

# 3. Page Table

A **Page Table** is a data structure that stores:

Page Number → Frame Number mapping


Example:

| Page | Frame |
|-----|------|
| 0 | 3 |
| 1 | 1 |
| 2 | 4 |
| 3 | 2 |

Meaning:


Page 0 stored in Frame 3
Page 1 stored in Frame 1


Each **process has its own page table**.

The page table is stored in **main memory** and its address is kept in **PTBR (Page Table Base Register)**. :contentReference[oaicite:2]{index=2}

---

# 4. Logical Address Structure

CPU generates **Logical Address**.

Logical address has two parts:

Page Number (p)
Offset (d)


Example:

Logical address space = **64 bytes**


2^6 = 64


So address uses **6 bits**.

Example address:


25 = 011001


Split into:


01 → Page Number
1001 → Offset


---

# 5. Address Translation (MMU)

Steps:

1. CPU generates logical address (p, d)
2. Page number **p** used to index page table
3. Page table returns **frame number**
4. Physical address formed:


Physical Address = Frame Number + Offset


Example:


Logical Address = (Page 2, Offset 5)

Page Table → Page 2 → Frame 4

Physical Address = Frame 4 + Offset 5


---

# 6. Why Paging is Slow?

Paging requires **two memory accesses**:

1. Access page table in memory
2. Access actual data in memory

So each instruction requires **extra memory reference**, making paging slow. :contentReference[oaicite:3]{index=3}

---

# 7. Translation Look-aside Buffer (TLB)

To speed up paging, hardware uses **TLB**.

TLB is:

- A **small high-speed cache**
- Stores recent **page → frame mappings**

---

## TLB Working

1. CPU generates logical address
2. TLB checked first

### Case 1: TLB Hit

Mapping found in TLB

Page -> Frame


Physical address generated immediately.

Fast.

---

### Case 2: TLB Miss

Mapping not found

Steps:

1. Access page table in memory
2. Get frame number
3. Store mapping in TLB
4. Continue execution

Slower.

---

# 8. Why TLB Makes Paging Fast

Without TLB:

2 Memory Accesses


With TLB:


Mostly 1 Memory Access


Because most translations are found in **TLB cache**.

---

# One-Line Revision

Paging divides logical memory into **pages** and physical memory into **frames**, uses a **page table for mapping**, and speeds up address translation using **TLB**.