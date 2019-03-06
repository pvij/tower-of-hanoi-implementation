# tower-of-hanoi-implementation

Tower of Hanoi implemented using C. The game involves three poles A, B and C and some disks arranged on pole A in increasing order of their size from top to bottom. the game requires us to shift the disks from pole A to pole C under the following rules: -

1. Only one disk can be shifted from one pole to another.
2. A larger disk cannot be placed on a smaller one.

The code takes in the number of disks present on pole A as follows and prints before and after scenarios (1 is the smallest (top-most) disk followed by other disks) as follows: -

Enter the no of disks on tower A:- 10

---BEFORE---
Pole A: 1 2 3 4 5 6 7 8 9 10 
Pole B: 
Pole C: 

---AFTER---
Pole A: 
Pole B: 
Pole C: 1 2 3 4 5 6 7 8 9 10

The code makes use of a stack, which is implemented using a linked list.

