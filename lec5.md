# 📞 System Calls in Operating System

## What is a System Call?

A **system call** is a mechanism using which a **user program requests a service from the kernel** that it does not have permission to perform directly.

User programs **cannot directly**:
- Access hardware (CPU, Disk, I/O devices)
- Communicate with kernel data structures
- Perform privileged operations

👉 **System calls are the only legal way for a process to switch from User Mode to Kernel Mode.**

---

## ❓ How do Applications Interact with Kernel?

### ✅ Answer: Using System Calls

### Explanation
- User interacts with system using **GUI or CLI**
- GUI and CLI both internally use **system calls**
- Example:
  - CLI: `mkdir test`
  - GUI: Right-click → New Folder  
  👉 Internally both call the **same system call**

### Important Points
- `mkdir` is **not** a system call
- It is a **wrapper** around an actual system call
- Between User Space and Kernel Space lies:
  - **System Call Interface (SCI)**

### System Call Interface (SCI)
- SCI maps user commands to corresponding kernel functions
- It decides **which kernel service to execute**

### Language Used
- Most system calls are written in **C language**

---

## 🔄 System Call Execution Flow

User Program

↓

Library Function (wrapper like mkdir)

↓

System Call Interface

↓

Kernel Mode Execution

↓

Return value

↓

User Mode



### Example Flow
1. User executes a program (User Space)
2. Program requests a system call
3. Kernel executes it (Kernel Mode)
4. Control returns back to User Space

---

## 📂 Types of System Calls

---

## 1️⃣ Process Control System Calls

### Purpose
- Process creation, execution, termination
- Memory allocation
- Process synchronization

### Common System Calls
- end, abort
- load, execute
- create process, terminate process
- wait, signal
- allocate / free memory

### Linux Commands & Use Cases

| Command | Use Case | Example |
|------|--------|--------|
| `ps` | Show running processes | `ps aux` |
| `top` | Live process monitoring | `top` |
| `kill` | Terminate process | `kill 1234` |
| `fork()` | Create child process | Used internally |
| `exec()` | Replace process image | `exec ls` |
| `wait` | Wait for child process | `wait` |
| `sleep` | Delay execution | `sleep 5` |

---

## 2️⃣ File Management System Calls

### Purpose
- File creation, deletion
- Read / write operations
- File attributes handling

### Common System Calls
- create, delete
- open, close
- read, write
- reposition (lseek)
- get/set file attributes

### Linux Commands & Use Cases

| Command | Use Case | Example |
|------|--------|--------|
| `touch` | Create file | `touch file.txt` |
| `rm` | Delete file | `rm file.txt` |
| `open()` | Open file | Used internally |
| `cat` | Read file | `cat file.txt` |
| `echo` | Write to file | `echo "hi" > a.txt` |
| `chmod` | Change permissions | `chmod 755 file.txt` |
| `stat` | File attributes | `stat file.txt` |
| `lseek()` | Move file pointer | Used internally |

---

## 3️⃣ Device Management System Calls

### Purpose
- Request or release device
- Read/write device data
- Manage device attributes

### Common System Calls
- request device
- release device
- read, write
- get/set device attributes
- attach/detach devices

### Linux Commands & Use Cases

| Command | Use Case | Example |
|------|--------|--------|
| `lsusb` | List USB devices | `lsusb` |
| `mount` | Attach device | `mount /dev/sdb1 /mnt` |
| `umount` | Detach device | `umount /mnt` |
| `df` | Disk usage | `df -h` |
| `dd` | Low-level read/write | `dd if=a of=b` |

---

## 4️⃣ Information Maintenance System Calls

### Purpose
- Get or set system information
- Get or set attributes of process, file, device

### Common System Calls
- get/set time & date
- get/set system data
- get/set attributes

### Linux Commands & Use Cases

| Command | Use Case | Example |
|------|--------|--------|
| `date` | Get system date | `date` |
| `uptime` | System running time | `uptime` |
| `uname` | System info | `uname -a` |
| `id` | User info | `id` |
| `whoami` | Current user | `whoami` |
| `free` | Memory usage | `free -h` |

---

## 5️⃣ Communication Management System Calls

### Purpose
- Inter-process communication
- Message passing
- Network communication

### Common System Calls
- create/delete communication link
- send/receive messages
- transfer status info
- attach/detach remote devices

### Linux Commands & Use Cases

| Command | Use Case | Example |
|------|--------|--------|
| `pipe()` | Create pipe | `ls | grep txt` |
| `ipcs` | IPC status | `ipcs` |
| `msgsnd` | Send message | Used internally |
| `msgrcv` | Receive message | Used internally |
| `ssh` | Remote communication | `ssh user@host` |
| `scp` | File transfer | `scp a.txt user@ip:/home` |
| `netstat` | Network info | `netstat -an` |

---

## 🔑 Key Points (Exam Ready)

- System calls are **bridge between user space and kernel**
- User programs cannot access hardware directly
- GUI & CLI both internally use system calls
- System call interface maps user requests to kernel services
- Every system call involves **mode switching**

---

## 🧠 One-Line Revision

> **System call = Safe & controlled entry point from User Mode to Kernel Mode**

 