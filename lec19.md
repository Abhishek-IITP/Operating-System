# 📖 Reader–Writer Problem and Its Solution

---

## 📌 Problem Statement

Do types ke threads hote hain:

1️⃣ **Reader Thread**  
- Sirf data read karta hai  

2️⃣ **Writer Thread**  
- Data write/update karta hai  

---

## 🧠 Key Observations

- ✔️ **Multiple readers allowed simultaneously**
- ❌ **Multiple writers allowed nahi**
- ❌ **Writer + Reader together allowed nahi**
  - Warna race condition & data inconsistency ho sakti hai

👉 Rule:  
- Writing ke time **sirf 1 thread** critical section me ho
- Reading ke time **multiple readers allowed**

---

# 🧩 Critical Section Representation

            +----------------------+
            |   Shared Resource    |
            |   (Critical Section) |
            +----------------------+
                 ↑           ↑
             Readers      Writer


---

# 🔐 Semaphore-Based Solution (Reader Preference)

We use 3 shared variables:

---

## 1️⃣ mutex (Binary Semaphore)

- Protect karta hai **readCount (rc)**
- Ensure karta hai:
  - Do readers ek saath `rc` modify na karein

Initial value: mutex = 1;


---

## 2️⃣ wrt (Binary Semaphore)

- Controls access to shared resource
- Common for both readers & writers

Initial value: wrt = 1;


---

## 3️⃣ readCount (rc)

- Integer variable
- Track karta hai:
  - Kitne readers currently reading kar rahe hain

Initial value: rc =0;

## Writer solution

```
     do{
          wait(wrt); <!--Enter critical section-->
          // do write operation
          signal(wrt); <!--Exit Critical section-->
     } while(true);
```


### Explanation:
- Writer ko exclusive access chahiye
- Isliye `wrt` acquire karega
- Jab tak writer andar hai:
  - Koi reader ya writer enter nahi kar sakta

---

## Reader solution

```
     do{
          wait(mutex);  <!-- Lock read count -->
          rc++;
          if(rc == 1)
               wait(wrt); <!--ensure no writer can enter if there is even one reader present -->
          signal(mutex); <!-- Release readCount lock-->

                <!---- Critical Section (Reading) ---->
          wait(mutex); <!--Lock Read count-->
          rc--;
          if(rc ==0 ) <!-- no reader is left in critical section>
               signal(wrt); <!--writer can enter-->
          signal(mutex); <!--Release readCount lock-->
     }while(1)
```

---

# 🧠 How It Works

### Case 1: Multiple Readers

- First reader:
  - `rc = 1`
  - Locks `wrt`
- Other readers:
  - `rc > 1`
  - Directly enter

👉 All readers can read simultaneously

---

### Case 2: Writer

- Writer waits until:
  - `wrt` becomes available
- That happens only when:
  - `rc == 0`
  - No readers inside

👉 Writer gets exclusive access

---

# ⚠️ Problem with This Solution

- This is **Reader-Preference Solution**
- Writers may suffer **Starvation**
- If readers continuously arrive:
  - Writer kabhi enter nahi kar paayega

---

# 📊 Summary Table

| Scenario | Allowed? |
|-----------|----------|
| Multiple Readers | ✅ Yes |
| Multiple Writers | ❌ No |
| Reader + Writer | ❌ No |


---

# 🧠 One-Line Revision

**Reader–Writer problem allows multiple readers but only one writer at a time, solved using mutex, wrt semaphore, and readCount tracking**
