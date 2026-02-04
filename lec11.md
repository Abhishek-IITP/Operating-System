# 🔄 Context Switching | Medium Term Scheduler | Orphan & Zombie Process

---

## 🔁 What is Swapping?

### Swapping kya hota hai?
- Jab **main memory (RAM)** kam pad jaati hai
- OS kuch processes ko **temporarily memory se bahar** nikal deta hai
- Ye processes **secondary storage** me store hote hain

👉 Is process ko **Swapping** kehte hain

---

## 🧑‍💼 Medium Term Scheduler (MTS)

### Why Medium Term Scheduler is Needed?
- **Long Term Scheduler (LTS)** zyada processes admit kar deta hai
- Degree of multiprogramming **bahut zyada increase** ho jaata hai
- Memory shortage ho jaati hai → Ready Queue maintain karna mushkil

---

### What MTS Does?
- Kuch processes ko **Ready Queue se swap out** karta hai
- Swap out hone wale processes **swap space** me jaate hain

> **Swap Space** = Secondary storage ka part (disk)

---

### Purpose of MTS
- Memory load reduce karna
- Degree of multiprogramming control karna
- System stability maintain karna

---

## 🔄 Process States with Swapping (Concept)

- Ready <----> Swapped Out (Secondary Storage)


- Swap out → RAM → Disk  
- Swap in → Disk → RAM

---

## 🔁 Context Switching

### What is Context Switching?
- Jab CPU ek process se **dusre process** pe switch karta hai
- Current process ka state save hota hai
- Next process ka state restore hota hai

---

### What gets saved?
- Program Counter
- CPU Registers
- Process State
- Stack Pointer

👉 Ye sab data **PCB (Process Control Block)** me store hota hai

---

### When Context Switching Happens?
- Time quantum expire ho jaaye
- I/O request aaye
- Higher priority process arrive kare
- Process terminate ho jaaye

---

### Cost of Context Switching
- CPU time waste hota hai
- Isliye **excessive context switching bad** hoti hai

---

## 👶 Orphan Process

### What is Orphan Process?
- Jab **parent process terminate ho jaata hai**
- Lekin **child process still executing** hota hai

---

### Important Rule
- Normally parent `wait()` karta hai child ke liye
- Agar parent **unexpectedly terminate** ho jaaye:
  - Child process orphan ban jaata hai

---

### Who becomes new parent?
- **Init process (PID = 1)** automatically adopt kar leta hai
- Linux me ye `init` ya `systemd` hota hai

---

### Orphan Process Demonstration (Bash Script)

👉 **Script: orphan.sh**
```bash
#!/bin/bash

echo "Parent PID: $$"

(
  echo "Child PID: $$"
  sleep 10
  echo "Child still running..."
  ps -o pid,ppid,cmd -p $$
) &

sleep 1
echo "Parent exiting..."
exit
```


## ▶️ How to Run (Orphan Process Demo)

```
```bash
chmod +x orphan.sh
./orphan.sh
```

## 🧟 Zombie Process (Defunct Process)

### What is a Zombie Process?
- Jab **child process terminate** ho jaata hai  
- Lekin **parent `wait()` call nahi karta**  
- Child ka entry **process table** me reh jaata hai  

👉 **Zombie process = Dead but not cleaned**

---

## 🧩 Zombie Process Scenario



Parent ----wait (5 min)-----------------------|
     |                                       |
     fork                                    |
     |                                       |
Child ----execute (2 min)----exit()----Zombie (3 min)


---

## ❓ Why Zombie Exists?

Parent process ko child ka:
- Exit status  
- Execution information  

chahiye hota hai  

---

## ♻️ Reaping of Zombie Process

- Jab parent finally **`wait()` call** karta hai  
- OS:
  - Zombie ka **PCB remove** karta hai  
  - Process table **clean** ho jaati hai  

👉 Is process ko **Reaping** kehte hain  

---

## 🧪 Zombie Process Demo (Bash Script)

### 👉 Script: `zombie.sh`


```
#!/bin/bash

echo "Parent PID: $$"

(
  echo "Child PID: $$"
  sleep 2
  echo "Child exiting..."
  exit 0
) &

sleep 60

```
▶️ Run & Observe
```
chmod +x zombie.sh
./zombie.sh
```


## 💥 Resource Leak & Relation to Orphan / Zombie

---

### ❓ What is Resource Leak?

- Jab system resources free nahi hote:
  - Memory
  - Process table entries
  - File descriptors

---

## 🧟 Zombie & Resource Leak

- Zombie process consume karta hai:
  - **Process table entry**

- Agar zyada zombie processes ho jaaye:
  - Process table **full** ho sakta hai
  - New processes **create nahi ho paate**

---

## 👶 Orphan & Resource Leak

- Orphan process **safe** hota hai
- Init process automatically:
  - Child ko **adopt** karta hai
  - Child ko **reap** karta hai

👉 Isliye **Orphan dangerous nahi hota**, lekin **Zombie hota hai**

---

## 🧠 Key Differences (Exam Ready)

| Feature | Orphan | Zombie |
|--------|--------|--------|
| Parent alive? | ❌ No | ✅ Yes |
| Child alive? | ✅ Yes | ❌ No |
| PPID | 1 (init) | Original parent |
| Resource issue | ❌ No | ✅ Yes |
| Dangerous | No | Yes |

---

## 🧠 One-Line Revision

**Context switching saves & restores process state, MTS manages memory via swapping, Orphan is safe, Zombie causes resource leak**
