# Multi-Tasking vs Multi-Threading
---

### Process -> Program under execution

### .exe file -> Double click -> Process

### which means disk ke aandar program hota h, aur jb hum log us program ko double click krte h toh woh RAM me chala jata h aur isko hi Process bolte h.

## Multi_Threading

### Thread -> Light weight Process
- Threads are the part of the Process.
- Independetly Executes.
- Single sequence stream within a process.
- Process ke aandar ek chotta sa kaam h
- majorly yeah asynchronous task hota h .
- example:- your are create a JPG -> PNG converter
     - your logic say  you take 100 x 100 input as JPG and return 100 x 100 output as PNG
     - and suppose input image file is 100 x 200 , so now your logic is break.
     - so what we do we break the tasks into diff part , in your case we break 200 in 2 * 100, and perform our logic independently 
     - and in the end concatinate the outputs.
     - but the drawback is ki pahle ek task perform hoga then the other, aur hume dono tasks ko ek sath perform krna h.
     - so yaha MultiThreading ka concept aata h
     - so now what we do, we break the tasks into two part t1, t2 and give them into diff thread and threads are independent so they work parallely without any intruption.
     - now t1 return a1 and t2 return b1 at same time, and we merge them.
     - works only Multiprocessing Operating System.
- another example :- multiple tabs in a browser, Text-editor.     


## Difference Between Multi-Taskings and Multi-Threadings

Multi-Tasking:
1. More than 1 Processes being context switched.
2. Isolation & Memory Protection hota h.
3. Process Scheduling.
4. No. of CPU 1.


Multi-Threading:
1. Process divided into several different sub-tasks called Threads.
2. No Isolations & Memory Protection. 
3. Threads Scheduling.
4. No of CPU >=1.
5. concept od more thant 1 thread , threads are context switched.


### Threads Scheduling :-  
## Threads are scheduled for execution based on their priority, Even though threads are executing within the runtime, all threads are assigned processor time slices by the os.

## Difference Between Process Context Switching and Threadings Context Switching:

### Process Context Switching:
- Os save current state of process & switches to another process by restoring its state.
- Includes switching of memory address space.
- slow switching.
- CPU's cache state is flushed.


### Threadings Context Switching:
- Os saves current state of thread & switches to another thread of same process.
- Doesn't Includes switching of memory address space.
- Fast switching
- CPU cache state is preserved











