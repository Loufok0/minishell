# Minishell

## Overview

This project implements a simplified Unix-style shell written in C, designed for the curriculum at École 42. It supports command parsing, execution (including built-ins), environment variable management, and redirection handling.

## Features

* Parsing of command lines into structured tokens (commands, arguments, pipes, redirections)
* Execution of external programs via `fork` and `execve`
* Built-in commands (e.g., `cd`, `echo`, `exit`, etc.)
* Support for environment variables, expansion, and simple variable assignment
* Input/output redirection (`>`, `<`, `>>`) and pipeline support (`|`)
* Basic error handling and user feedback for invalid syntax or execution failures
* Modular code structure:

  * `builtins/` – implementation of built-in commands
  * `exec/` – handling of process creation and command execution
  * `parsing/` – lexer and parser logic
  * `vars/` – environment variable management
  * `libft/` – custom library utilities
  * `lib_utils/` – auxiliary helper functions

## Requirements

* Linux environment (tested on Arch Linux)
* GCC (or compatible C compiler)
* Makefile support
* POSIX compliant system calls (fork, execve, pipe, dup2, etc.)

## Installation & Build

```bash
git clone https://github.com/Loufok0/minishell.git  
cd minishell  
make  
```

After `make`, the executable `minishell` will be available in the project root.

## Usage

Launch the shell:

```bash
./minishell  
```

Typical operations inside the shell:

* Running external commands (`ls`, `grep`, etc.)
* Chaining commands with pipes: `ls | grep "txt"`
* Redirecting output: `echo "hello" > output.txt`
* Appending redirection: `cat input.txt >> log.txt`
* Changing directories: `cd /path/to/dir`
* Setting or exporting environment variables: `export VAR=value`

## Project Structure

```
minishell/
├── builtins/       # built-in command implementations  
├── exec/           # execution engine (fork/exec, pipelines)  
├── parsing/        # lexical analysis and parsing logic  
├── vars/           # environment & variable handling  
├── lib_utils/      # helper functions  
├── libft/          # 42 custom library  
├── Makefile        # build rules  
├── main.c          # entry point  
└── minishell.h     # project-wide definitions and prototypes  
```

## Conventions & Notes

* All code conforms to the Norm at École 42 (coding style, function length, etc.).
* Memory leaks are to be avoided; dynamic allocations must be freed appropriately.
* Signal handling is required (e.g., handling Ctrl-C, Ctrl-D as EOF) inside the shell.
* Error messages must match expected output for automated evaluation.
* The shell must return appropriate exit codes (0 for success, non-zero for errors).

## Limitations

* No support for command substitution (`$(...)`) or backticks.
* No job control (background processes, `fg`, `bg`).
* No advanced shell features like aliasing or scripting support.
* Parsing and error recovery may be simplistic in complex syntax cases.
