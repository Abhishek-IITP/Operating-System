# ❓ OS kya hota hai aur OS ki zarurat kyun hoti hai?

## 📌 OS kya hota hai?

### Technical Term :
- An OS is a piece of software that manage all the resources of a computer system, both hardware and software and provides an enviroment in which the user can execte his/her program in a conveninet and efficient manner by hiding undelying complexity of the hardware and acting as a resource manager.

OS (Operating System) ek **beech ka layer** hota hai jo  
**Applications** aur **Hardware (CPU, Memory, GPU, Disk)** ke beech kaam karta hai.

---

## 🤔 OS ki zarurat kyun hoti hai?

### 🚫 Agar OS na ho
Maan lo humare system me **OS ka concept hi nahi hai**.

Ab hum ek app download karte hain, maan lo **Instagram**.

Kisi bhi app ko chalne ke liye chahiye:
- CPU
- Memory (RAM)
- GPU
- Disk

Agar OS nahi hoga:
- Instagram directly hardware use karega
- Wo **100% CPU, Memory, GPU** use kar sakta hai
- Jab hum **WhatsApp** ya koi aur app open karenge
- Instagram us app ko open hi nahi hone dega

Matlab:
- Ek app system ke saare resources kha jayega
- System unstable ho jayega
- Koi control nahi rahega



---

### ✅ OS hone par kya hota hai
Yahin pe **Operating System ka role aata hai**.

OS kya karta hai:
- Os ek **Interface** ki tarah kaam krta h
- Har app ko **limited resources** deta hai
- Instagram ko utna hi CPU / Memory deta hai jitna use chahiye
- Agar hum WhatsApp ya koi aur app open karte ho OS usko bhi resources de deta hai

Isse:
- Multiple apps ek saath kaam kar paate hain
- System smooth chalta hai
- Koi app dusre app ko block nahi karta

---

## 🧠 OS ke main kaam
- Resources ko manage karna
- Har app ko control me rakhna
- Multiple apps ko ek saath chalana
- System ko safe aur stable rakhna


##### OS ni hoga toh jo developers h unhe har application ke liye memory management & resource management(**Arbitration**) ka code likhna hoga, Jiski wajah se application bulky ho jayegi, aur yeah kaam sare application ke developers ko krna hoga aur yeah krne ke wajah se ****DRY Principle**** ka violation ho jayega & what is DRY it is **Don't repeat yourself** 
#### So OS kya krta h ki woh yeah memory & resource management ka code khud ke andar likh leta h, jisse ke woh har jagah us logic ko implement kre. 
#### Hum user ko kuch ni krna bs malloc call kro aur hume memory mil jayegi without any hassel.(in c++)

## OS also helps in isolation and protection 

- OS kya krega ki woh sare apps ko diff diff memory allocate krega.
- Instagram ko pta bhi ni chalega ki koi dusra app bhi run kr rha h.
- OS make sure krega ki app aapne alloted memory se bahar toh ni ja rha na

---

## 📊 System ka simple structure

+----------------------+
| Applications |
| (Instagram, WhatsApp)|
+----------------------+

| OS |

+----------------------+
| CPU | RAM | GPU | Disk |
+----------------------+

