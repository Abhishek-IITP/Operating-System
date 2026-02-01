# 💾 Types of Storage in Computer System

Computer storage ko mainly **Primary Memory** aur **Secondary Memory** me divide kiya jata hai.

---

## 🥇 Primary Memory (Internal Memory)

Primary memory CPU ke **direct access** me hoti hai.  
Ye memory **fast hoti hai**, lekin **expensive** aur **limited size** ki hoti hai.

---

### 1️⃣ Registers

- CPU ke **sabse closest** hote hain
- **Fastest access time**
- **Most expensive** memory
- Storage size **bahut small**
- Ek register generally **32-bit ya 64-bit data** store karta hai
- **Volatile memory** (power off → data lost)

👉 Used for:
- Instructions execution
- Temporary data storage during computation

---

### 2️⃣ Cache Memory

- CPU aur Main Memory ke beech hoti hai
- Frequently used data ko store karti hai
- Registers se slow, RAM se fast
- **Expensive** but faster than RAM
- **Volatile memory**

#### Levels of Cache
- **L1 Cache** – Fastest, smallest, inside CPU
- **L2 Cache** – Medium speed & size
- **L3 Cache** – Larger, shared among cores

---

### 3️⃣ Main Memory (Primary Memory / RAM)

- Programs execution ke time yahin load hote hain
- CPU directly RAM se data access karta hai
- Cache se slow, secondary storage se fast
- **Volatile memory**
- Size zyada hota hai (GBs)

#### Types of RAM
- **SRAM** – Fast, costly (used in cache)
- **DRAM** – Slow, cheap (used as main memory)

---

## 📌 Summary: Primary Memory

| Type | Speed | Cost | Size | Volatile |
|----|-----|----|----|---------|
| Registers | Fastest | Highest | Very small | Yes |
| Cache | Very fast | High | Small | Yes |
| RAM | Fast | Medium | Large | Yes |

---

## 🥈 Secondary Memory (External Memory)

Secondary memory CPU ke **direct access** me nahi hoti.  
Data ko **permanently store** karne ke liye use hoti hai.

---

### 4️⃣ Electronic Disk (Solid State Storage)

- No moving parts
- Very fast compared to HDD
- Non-volatile memory
- Expensive per GB

#### Examples
- SSD
- Flash Drive
- Memory Card

---

### 5️⃣ Magnetic Disk

- Data magnetic coating me store hota hai
- Rotating disks (moving parts)
- Slower than SSD, faster than tapes
- Non-volatile

#### Examples
- Hard Disk Drive (HDD)

---

### 6️⃣ Optical Disk

- Data laser ke through read/write hota hai
- Slower access time
- Used for distribution & backup

#### Examples
- CD
- DVD
- Blu-ray

---

### 7️⃣ Magnetic Tape

- Sequential access memory
- Very slow compared to disks
- Very cheap
- Used for backup & archival

#### Examples
- Tape drives

---

## 📊 Summary: Secondary Memory

| Type | Speed | Cost | Access |
|----|-----|----|-------|
| Electronic Disk (SSD) | Very fast | High | Random |
| Magnetic Disk (HDD) | Medium | Low | Random |
| Optical Disk | Slow | Low | Random |
| Magnetic Tape | Very slow | Very low | Sequential |

---

## 🧠 Memory Hierarchy (Top → Bottom)

Registers

↓

Cache Memory

↓

Main Memory (RAM)

↓

Electronic Disk (SSD)

↓

Magnetic Disk (HDD)

↓

Optical Disk

↓

Magnetic Tape

## 🔑 Key Points
- Upper level → Faster, smaller, expensive
- Lower level → Slower, larger, cheaper
- Primary memory is volatile
- Secondary memory is non-volatile
