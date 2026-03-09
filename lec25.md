# How OS Manages Free Space? | Memory Management

---

# Free Space Management

Operating System **tracks free memory using a Free List**.

**Free List** = list of all unused memory blocks in RAM.

When a new process arrives:

1. OS searches free list
2. Finds suitable free block
3. Allocates memory to the process

Problem:

External Fragmentation


Memory free hoti hai but **small scattered blocks me**.

---

# Defragmentation / Compaction

Dynamic partitioning me **external fragmentation** hota hai.

To solve this OS uses:

Compaction (Defragmentation)


### Idea

- All **allocated processes** ko ek side move kar diya jata hai
- All **free spaces** ko ek single block me merge kar diya jata hai

Result:

- Large contiguous free memory block mil jata hai
- Large process load ho sakta hai

---

### Before Compaction

  16 ----------------                
     |              |
     |    FS - 2KB  |
     |              |
  12 ----------------
     |              |
     |   P3 - 8KB   |
     |              |          
   6 ----------------
     |              |
     |    FS - 2KB  |
     |              |
   4 ----------------
     |              |
     |    OS        |
     |              |
   0 ----------------
          RAM

---

### After Compaction


  16 ----------------
     |              |
     |    FS - 4KB  |
     |              |
  12 ----------------
     |              |
     |    P3 - 8KB  |
     |              |
   4 ----------------
     |              |
     |    OS        |
     |              |
   0 ----------------

     DEFRAGMENTED RAM



Now free spaces merge ho gaye.

---

### Disadvantage

Compaction expensive hota hai because:

- Processes move karne padte hain
- CPU time waste hota hai
- System performance slow ho sakti hai

---

# Allocation Methods in Contiguous Memory

When a process arrives, OS must decide **which free block to allocate**.

Four major algorithms:

1. FIRST-FIT
2. NEXT-FIT
3. BEST-FIT
4. WORST-FIT


---

# 1️⃣ First Fit

OS **first suitable free block** allocate karta hai.

### Steps

1. Free list start se search
2. Jo first block large enough ho
3. Usko allocate kar do

Example
Free blocks: 5KB | 8KB | 3KB | 6KB
Process: 4KB


Allocated block:
5KB block


---

### Advantages

- Fast
- Simple
- Low overhead

### Disadvantages

- External fragmentation
- Small holes accumulate at beginning

---

# 2️⃣ Next Fit

First Fit jaisa hi hai.

Difference:

Search **last allocated position** se start hota hai.

Example

Free blocks: 5KB | 8KB | 3KB | 6KB
Last allocation at block 8KB


Search starts **after 8KB**.

---

### Advantages

- Faster than First Fit in large memory
- Less repeated scanning

### Disadvantages

- Memory utilization slightly worse
- Fragmentation still exists

---

# 3️⃣ Best Fit

OS **smallest possible free block** choose karta hai.

Goal:

Minimize leftover space


Example


Free blocks: 5KB | 8KB | 3KB | 6KB
Process: 4KB


Best fit: 5KB block


(closest size)

---

### Advantages

- Minimum internal fragmentation

### Disadvantages

- Slow (must scan entire list)
- Creates many small unusable holes

---

# 4️⃣ Worst Fit

OS **largest free block** allocate karta hai.

Idea: Leave large leftover blocks

Example

Free blocks: 5KB | 8KB | 3KB | 6KB
Process: 4KB

Allocated block: 8KB block
Remaining: 4KB free


---

### Advantages

- Large leftover blocks remain usable

### Disadvantages

- Poor memory utilization
- Rarely used in practice

---

# Comparison of Allocation Algorithms

| Algorithm | Speed | Fragmentation | Idea |
|--------|------|--------------|------|
| First Fit | Fast | Medium | First suitable block |
| Next Fit | Fast | Medium | Continue from last position |
| Best Fit | Slow | High external fragmentation | Smallest possible block |
| Worst Fit | Slow | Poor utilization | Largest block |

---

# One-Line Revision

OS manages free memory using a free list, reduces fragmentation using compaction, and allocates memory using algorithms like First Fit, Next Fit, Best Fit, and Worst Fit.
