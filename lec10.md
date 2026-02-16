# What are different Process States in Operating System ?

##What is Process state : - 
 -> Life cycle
 -> Generation to Termination.
 1. New State - 
- Program -> process , being done

2. Ready -
- Process is in memory 
- in ready queue

3. Running State - 
- P1 process -> cpu allocate

4. Waiting State -
- waiting I/O completion.

5. Termination State - 
- Process is finished.

create a diagram to make all the above things clear


Job schedular :- ek pool se bohut sare jobs ko pick krta h aur ready state pe bhejta h.
- also known as long term schedular(LTS).
CPU schedular :- ready state se Termination state pe bhejne ka kaam cpu schedular ka hota h.
also known as short term schedular(STS). explain why is is short term schedular and same for long term schedular too.

degree of multi-Programming :- ek baari me kitne sare process ready queue me rah skte h. and this was managed by LTS .

dispatcher :-  The module of os that gives control  of CPU to a process selected by STS.
