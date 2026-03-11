# Segmentation in OS | Non-Contiguous Memory Allocation

---

# 1. Problem in Paging

Paging divides memory into **fixed size pages**.

But paging has a major issue:

### ❌ Separation of User View and Memory

User thinks program has logical parts like:

- main function
- functions
- stack
- heap
- libraries

But paging **randomly divides program into pages**, so:

main() → page 0
function → page 3
library → page 1


Related code may be stored in **different pages**.

OS does not care about **logical structure of program**, which reduces efficiency. :contentReference[oaicite:0]{index=0}

---

# 2. What is Segmentation?

Segmentation is a memory management technique that **supports the user's view of memory**. :contentReference[oaicite:1]{index=1}

Instead of fixed pages, the program is divided into **logical segments**.

Example segments:
Segment 0 → Code
Segment 1 → Data
Segment 2 → Stack
Segment 3 → Heap
Segment 4 → Libraries


Each segment represents a **logical part of program**.

---

# 3. Logical Address in Segmentation

Logical address has two parts:

<Segment Number , Offset>
<s , d>


Example:


<2 , 100>


Meaning:


Segment 2
Offset 100 inside that segment


---

# 4. Segment Table

Each process has its **own Segment Table**.

Segment table stores:

| Segment | Base | Limit |
|-------|------|------|
| 0 | 1000 | 400 |
| 1 | 2000 | 300 |
| 2 | 5000 | 200 |

Where:

- **Base** → starting physical address of segment
- **Limit** → maximum size of segment

---

# 5. Address Translation in Segmentation

Steps:

1. CPU generates logical address:
<s,d>

2. Segment number **s** used to index **segment table**

3. Check: d < limit


If false → **trap (error)**

4. Physical address calculated:

Physical Address = Base + Offset


---

# Example

Logical address:


< 1 , 50 >

Segment table entry:


Segment 1
Base = 2000
Limit = 300

Check:

50 < 300 ✔


Physical address:


2000 + 50 = 2050


---

# 6. Advantages of Segmentation

✔ Matches **user view of memory**  
✔ No internal fragmentation  
✔ Related code stored together  
✔ Smaller segment table than page table

---

# 7. Disadvantages of Segmentation

❌ External fragmentation  
❌ Variable size segments difficult to manage  
❌ Swapping becomes complex

---

# Important Note

Modern operating systems usually use **Hybrid approach**:


---

# One-Line Revision

Segmentation divides a program into **logical variable-size segments** and uses **segment tables (base + limit)** to translate logical addresses into physical addresses.