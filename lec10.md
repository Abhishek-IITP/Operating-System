# Process States in Operating System

## What is a Process State?

A **process state** represents the current stage of a process in its life cycle, from creation to termination.

A process moves through different states depending on CPU availability and resource requirements.

---

# Five Main Process States

## 1. New State
- Program is being converted into a process.
- OS creates the Process Control Block (PCB).
- Memory and resources are allocated.
- Process is not yet ready to execute.

## 2. Ready State
- Process is loaded into main memory.
- Waiting in the **ready queue**.
- Waiting for CPU allocation.

## 3. Running State
- CPU is allocated to the process.
- Instructions are being executed.
- Only one process per CPU can be in this state at a time.

## 4. Waiting (Blocked) State
- Process is waiting for some event.
- Mostly waiting for I/O completion.
- Example: disk read, keyboard input, network response.

## 5. Terminated State
- Process finishes execution.
- OS releases memory and other resources.
- Process life cycle ends.

---

# Process State Transition Diagram
```
            +------+
            | New  |
            +------+
                |
                |  (Admitted by Long Term Scheduler)
                v
            +--------+
            | Ready  |<-----------------------------+
            +--------+                              |
                |                                    |
                |  (Selected by Short Term Scheduler)|
                v                                    |
            +----------+                             |   
            | Running  |                             |
            +----------+                             |
             |        |                              |
 (I/O Request)|        | (Process Completes)         |
             v        v                              |
       +----------+  +------------+                  |
       | Waiting  |  | Terminated |                  |
       +----------+  +------------+                  |
             |                                         
             | (I/O Completed)                        
             +-----------------------------------------+
                               |
                               v
                            +--------+
                            | Ready  |
                            +--------+
```


---

# Job Scheduler (Long Term Scheduler - LTS)

## Definition
The Job Scheduler selects processes from the job pool (secondary storage) and moves them into the ready queue.

## Why is it called Long Term Scheduler?

- It runs less frequently.
- It controls how many processes enter memory.
- It manages the **degree of multiprogramming**.
- It makes long-term decisions about system load.

---

# CPU Scheduler (Short Term Scheduler - STS)

## Definition
The CPU Scheduler selects one process from the ready queue and allocates the CPU to it.

## Why is it called Short Term Scheduler?

- It runs very frequently.
- It makes decisions in milliseconds.
- It selects the next process whenever the CPU becomes free.
- It handles quick switching decisions.

---

# Degree of Multiprogramming

## Definition
The number of processes present in memory (ready queue) at a time.

Example:  
If 5 processes are in memory ready to execute,  
Degree of multiprogramming = 5

## Managed By
Long Term Scheduler (LTS)

Reason:  
Because LTS controls how many processes are admitted into memory.

---

# Dispatcher

## Definition
The Dispatcher is the OS module that:

- Gives control of CPU to the process selected by Short Term Scheduler.
- Performs context switching.
- Switches from kernel mode to user mode.
- Starts execution of the selected process.

### Flow

Short Term Scheduler → Selects process  
Dispatcher → Gives CPU control  

---

# Complete Process Flow

1. Program created → New  
2. LTS admits → Ready  
3. STS selects → Running  
4. Needs I/O → Waiting  
5. I/O complete → Ready  
6. Execution finished → Terminated  
