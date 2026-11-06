# Operating Systems - Assignment 1 (Fall 2025)

## 📌 Project Overview
This repository contains C program solutions for Assignment 1 of the Operating Systems course. The assignment focuses on **Process Management**, demonstrating how operating systems handle process creation, execution replacement, and synchronization through system calls.

---

## 💻 Assignment Problems & Implementations

### **Q1: Process Duplication and PID Relationship (`fork()`)**
* **Objective:** Demonstrate process creation and hierarchy using `fork()`.
* **Key Features:**
  * Prints the Process ID (PID) and Parent Process ID (PPID) for both parent and child processes.
  * Implements timing behavior where the child sleeps for 3 seconds while the parent prints periodic status messages until termination is detected.
  * Clear labeling of parent vs. child execution blocks in the standard output.

### **Q2: Executing a New Program with `exec()`**
* **Objective:** Combine `fork()` with an `exec()` system call to load and run a new program within a child process.
* **Key Features:**
  * Uses `execlp()` to replace the child process image with the UNIX `ls -l` command.
  * The parent process blocks using `wait()` until the child finishes execution before printing a completion message.

### **Q3: Combining Multiple Forks and Execs**
* **Objective:** Manage multiple child processes running concurrently from a single parent.
* **Key Features:**
  * Creates two separate child processes using two `fork()` calls.
  * The first child executes the `date` command using `execvp()`.
  * The second child executes the `whoami` command using `execlp()`.
  * The parent process waits for **both** children to terminate successfully before printing the final confirmation message.

---

## 🛠️ Tech Stack & Requirements
* **Language:** C
* **Environment:** Linux / UNIX-based terminal (GCC compiler)
* **System Calls Used:** `fork()`, `exec()`, `execlp()`, `execvp()`, `wait()`, `getpid()`, `getppid()`, `sleep()`
