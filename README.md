## Simple Shell - Super Friendship Shell

A basic shell done in C.  Detailed list of features forthcoming.

|     *Filename*     |               *Description*                      |
|--------------------|--------------------------------------------------|
| shell.h            | Header file containing function declaractions    |
| main.c             | Main .c source file for project                  |
| sfsh.h             | Header file for our Super Friendship Shell       |
| sfsh_loop.c        | Entry point hands off to our Shell's loop        |
| sfsh_getline.c     | Function takes in command and argument as string |
| sfsh_tokenize.c    | Function breaks up string with delimiters        |
| sfsh_execute.c     | Matches commands with supported builtins         | 
| sfsh_launch.c      | Creates child process to execute function        | 
| sfsh_helpers.c     | Helper functions for the Super Friendship Shell  | 
| sfsh_builtins0.c   | Implementation of built-in functions             | 

## Environment
The Super Friendship Shell was built in Ubuntu 14.04 LTS in a virtual 
machine managed by Vagrant.

## Prerequisites
Please have the following installed in your Ubunutu 14.04 environment:
- git (sudo apt-get install git)
- build-essential (sudo apt-get install build-essential) 

## How to Install
Clone the repository to a directory of your choice
'''
https://github.com/henryh28/simple_shell.git
'''

## How to Compile
After cloning the repository, please run the following the command...
'''
gcc -Wall -Werror -Wextra -pedantic *.c -o sfsh
'''

## Run the executuable
Type this command to execute the Super Friendship Shell!
'''
./sfsh
'''

## Authors
*Dave Yoon* - [Github](https://github.com/daveyoon64)

*Henry Hsu* - [Github](https://github.com/henryh28)
