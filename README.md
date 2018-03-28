# Shell
### Description
This project is a recreation of the command-line interpreter (shell).
Functionally, this project  mirrors `sh` in a limited scope.
### Synopsis
This version of the shell has a collection of custom built-in commands along
with the functionality of running scripts in the the various paths on a given operating system.
### Environment
Our Shell has been tested on Ubuntu 14.05.5 LTS.
Tests done in VirtualBox on [Ubuntu](https://atlas.hashicorp.com/ubuntu/boxes/trusty64) via [Vagrant](https://www.vagrantup.com/)(1.9.1)

## Repo Contents

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
|  `shell.h`	|  Header file: contains prototypes	|
|  `main.c`	|  Main file				|
|  `_builtin.c` |  Functions to execute builtins|
|  `_env.c` |  Environmental variable list	|
|  `_error.c`	|  Functions to print error messages|
|  `_exit.c`  |  Exit function	 |
|  `_reaaloc.c`  | Helper function to re allocate memory   |
|  `_strtok.c`	    |  Custom strtok function	|
|  `helper_func.c`  | String helper functions	|
|  `helper_func2.c  | More helper functions  |
|  `path.c`  | Functions for handling the PATH  |
|  `tokenizer.c  | Function to tokenize string  |

### How to Use
Clone repo
```
git clone https://github.com/MitaliSengupta/simple_shell.git
```
Change directory to simple_shell
```
cd simple_shell/
```
Compile all the `.c` files in /simple_shell
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```