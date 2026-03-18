# Non-Preemptive Priority CPU Scheduling in C

## 📌 Description

This project implements **Non-Preemptive Priority CPU Scheduling** in C.

* Higher priority value → Higher priority
* Processes are scheduled based on priority after arrival

## 📥 Input Format

```
n
PID AT BT PR
```

Example:

```
5
P1 0 5 2
P2 0 4 5
P3 1 3 1
P4 2 3 4
P5 3 2 3
```

## 📤 Output

* Completion Time (CT)
* Turnaround Time (TAT)
* Waiting Time (WT)

## ⚙️ Algorithm

1. Sort processes by arrival time
2. Among available processes, pick highest priority
3. Execute fully (non-preemptive)
4. Repeat until all processes complete

## 💻 Language

C

## 📁 Files

* `priority.c` → Main program
