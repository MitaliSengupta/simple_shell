# Shell
### Description
This project is a recreation of the command-line interpreter (shell).
Functionally, this project  mirrors `sh` in a limited scope.
### Synopsis
This version of the shell has a collection of custom built-in commands along
with the functionality of running scripts in the the various paths on a given operating system.
### Environment
Our Shell has been tested on Ubuntu 14.05.5 LTS.
Tests done in VirtualBox on [Ubuntu](https://atlas.hashicorp.com/ubuntu/boxes/trusty64) via [Vagrant](https://www.vagrantup.com/)(2.0.1)

## Repo Contents

|   ***File***    |  **Decription**                       |
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
### Interactive and Non-Interactive Mode
In interactive mode input is accepted from character input.
```
$ ./hsh
$ ls -l
total 88
-rw-rw-r-- 1 vagrant vagrant   158 Mar 21 15:58 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2379 Mar 27 18:56 _builtin.c
-rw-rw-r-- 1 vagrant vagrant  2480 Mar 28 04:32 _env.c
-rw-rw-r-- 1 vagrant vagrant   454 Mar 27 19:04 _error.c
-rw-rw-r-- 1 vagrant vagrant   620 Mar 28 04:32 _exit.c
-rw-rw-r-- 1 vagrant vagrant  1434 Mar 27 19:22 helper_func2.c
-rw-rw-r-- 1 vagrant vagrant  1984 Mar 28 04:32 helper_func.c
-rwxrwxr-x 1 vagrant vagrant 18796 Mar 28 05:38 hsh
-rw-rw-r-- 1 vagrant vagrant  1507 Mar 28 04:32 main.c
-rw-rw-r-- 1 vagrant vagrant  3469 Mar 28 04:28 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant  3418 Mar 27 19:09 path.c
-rw-rw-r-- 1 vagrant vagrant  1495 Mar 28 05:13 README.md
-rw-rw-r-- 1 vagrant vagrant   484 Mar 27 19:05 _realloc.c
-rw-rw-r-- 1 vagrant vagrant  2049 Mar 27 19:59 shell.h
-rw-rw-r-- 1 vagrant vagrant  1106 Mar 27 19:06 _strtok.c
-rw-rw-r-- 1 vagrant vagrant   727 Mar 27 19:18 tokenizer.c
$ echo hello world
hello world
$
```

In non-interactive mode, the shell is run from commands being piped in. The subshell
is only opened as the command is carried out and closes at the completion of the command.

```
$ ls -l | ./hsh
total 88
-rw-rw-r-- 1 vagrant vagrant   158 Mar 21 15:58 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2379 Mar 27 18:56 _builtin.c
-rw-rw-r-- 1 vagrant vagrant  2480 Mar 28 04:32 _env.c
-rw-rw-r-- 1 vagrant vagrant   454 Mar 27 19:04 _error.c
-rw-rw-r-- 1 vagrant vagrant   620 Mar 28 04:32 _exit.c
-rw-rw-r-- 1 vagrant vagrant  1434 Mar 27 19:22 helper_func2.c
-rw-rw-r-- 1 vagrant vagrant  1984 Mar 28 04:32 helper_func.c
-rwxrwxr-x 1 vagrant vagrant 18796 Mar 28 05:38 hsh
-rw-rw-r-- 1 vagrant vagrant  1507 Mar 28 04:32 main.c
-rw-rw-r-- 1 vagrant vagrant  3469 Mar 28 04:28 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant  3418 Mar 27 19:09 path.c
-rw-rw-r-- 1 vagrant vagrant  1495 Mar 28 05:13 README.md
-rw-rw-r-- 1 vagrant vagrant   484 Mar 27 19:05 _realloc.c
-rw-rw-r-- 1 vagrant vagrant  2049 Mar 27 19:59 shell.h
-rw-rw-r-- 1 vagrant vagrant  1106 Mar 27 19:06 _strtok.c
-rw-rw-r-- 1 vagrant vagrant   727 Mar 27 19:18 tokenizer.c
```
### Builtins and commands
Below are some of the builtin commands used, for further information please refer to the man page - accessed in terminal with:
```
man ./man_1_simple_shell
```
#### Builtins:
* `env` (prints environmental variables)
* `exit` (exit program)
* `pwd` (prints current working directory)
* `setenv` (sets a new environmental variable)
* `unsetenv` (unsets an environmental variable)

### Function and System Calls Used
`close`, `execve`, `exit`, `fork`, `free`, `getline`, `malloc`, `perror`, `wait`

## Notes
This shell does not handle aliases, comments, or history.

### Authors
*Andrew Keil* - [Github](https://github.com/Andkeil) || [Twitter](https://twitter.com/andkeil) || [email](andrew.keil@holbertonschool.com)

*Mitali Sengupta* - [Github](https://github.com/MitaliSengupta/) || [Twitter](https://twitter.com/aadhiBangalan) || [email](mitali.sengupta@holbertonschool.com)