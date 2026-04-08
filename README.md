# 🔀 pipex

A UNIX-based project developed as part of the **42 School curriculum**, focused on recreating **shell piping and redirection mechanisms** in C.
This project provides a deep understanding of how commands are chained together using pipes in a Unix environment.

---

## 📖 Overview

**pipex** is a program that mimics the behavior of shell commands like:

```bash
< infile cmd1 | cmd2 > outfile
```

The goal is to reproduce this pipeline using low-level system calls such as `fork`, `execve`, `pipe`, and `dup2`.

The project emphasizes:

* Understanding UNIX process execution
* Working with pipes and file descriptors
* Managing input/output redirection
* Building command execution pipelines

It allows you to explore how shell commands communicate through streams internally.

---

## 🧠 Learning Objectives

By completing this project, you will gain experience with:

* Process creation (`fork`)
* Program execution (`execve`)
* Inter-process communication (pipes)
* File descriptor manipulation (`dup2`, `close`)
* Input/output redirection
* Error handling in system-level programming

---

## 📂 Project Structure

```id="px1a2b"
pipex/
├── src/            # Source files
├── include/        # Header files
├── libft/          # Custom C library dependency
├── Makefile        # Build system
└── README.md
```

Typical components include:

* Command parsing and path resolution
* Pipe creation and management
* Process handling (parent/child processes)
* Error checking and cleanup

---

## ⚙️ Program Behavior

The program replicates shell piping behavior:

```bash id="pxcmd1"
./pipex infile "cmd1" "cmd2" outfile
```

Equivalent to:

```bash id="pxcmd2"
< infile cmd1 | cmd2 > outfile
```

### Flow

1. Read input from `infile`
2. Execute `cmd1`
3. Pipe output to `cmd2`
4. Write final result to `outfile`

---

## 🧩 How It Works

A typical implementation follows these steps:

### 1. Create a Pipe

* Use `pipe()` to create a communication channel
* Provides two file descriptors:

  * Read end
  * Write end

---

### 2. Fork Processes

* Create child processes using `fork()`
* Each command runs in its own process

---

### 3. Redirect Input/Output

* Use `dup2()` to:

  * Redirect input (`stdin`)
  * Redirect output (`stdout`)

---

### 4. Execute Commands

* Use `execve()` to run commands
* Replace process image with the desired program

---

### 5. Close Unused File Descriptors

* Prevent leaks and ensure proper communication

---

### 6. Wait for Processes

* Parent process waits for child processes to finish

---

## 🔁 Execution Diagram

```text id="pxflow1"
[infile] → [cmd1] → (pipe) → [cmd2] → [outfile]
```

Data flows through the pipe exactly like in a shell environment.

---

## ⚙️ Compilation & Usage

To build the program:

```bash id="pxbuild1"
make
```

### Cleaning

```bash id="pxclean1"
make clean      # Remove object files
make fclean     # Remove object files + binary
make re         # Rebuild everything
```

---

## 🚀 How to Use

```bash id="pxrun1"
./pipex input.txt "grep hello" "wc -l" output.txt
```

This will:

* Search for "hello" in `input.txt`
* Count matching lines
* Save the result in `output.txt`

---

## 🌟 Bonus Features (Optional)

Many implementations include:

* Support for multiple pipes (more than 2 commands)
* Handling `here_doc` (heredoc input)
* Improved error handling and edge case coverage
* (All of those are handled)

---

## 📌 Constraints

* Limited allowed functions:

  * `open`, `close`, `read`, `write`
  * `malloc`, `free`
  * `fork`, `execve`, `pipe`, `dup2`, `wait`
* Must not use system shell directly
* Must handle invalid commands and paths
* Must properly manage file descriptors

---

## 🎯 Key Concepts Covered

| Category           | Topics                    |
| ------------------ | ------------------------- |
| System Programming | Processes, system calls   |
| UNIX Internals     | Pipes, file descriptors   |
| Concurrency        | Parent/child processes    |
| I/O Redirection    | stdin/stdout manipulation |
| Debugging          | Process and pipe errors   |

---

## 🚀 Purpose of the Project

The **pipex** project is designed to:

* Teach how shell pipelines work internally
* Develop skills in system-level programming
* Build a strong understanding of process communication
* Prepare for more advanced UNIX and networking projects

---

## ⚠️ Notes

* Proper file descriptor handling is critical
* Incorrect pipe usage can cause deadlocks or leaks
* Debugging requires understanding process flow
* Behavior should closely match shell execution

---

## 🤝 Contributing

Contributions and improvements are welcome!

1. Fork the repository
2. Create a feature branch
3. Submit a pull request

---

## 📄 License

This project is for educational purposes.
Refer to the repository for licensing details (if provided).

---

## 📚 Resources

To deepen your understanding:

* `man pipe`
* `man fork`
* `man execve`
* `man dup2`
* UNIX process and file descriptor documentation

---
