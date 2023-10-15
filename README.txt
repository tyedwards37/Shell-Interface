#READ.ME

Project: Shell Interface
by Tyler Edwards 
Added October 2023

Description: A C program that acts as a shell interface where a user can input commands. It takes each command and runs it as a seperate process. The parent process will wait for the child process to finish, unless a "&" is included as an argument. In that case, the parent and child will run concurrently.

Language: C 

Reason: For CPSC 380 (Operating Systems)

Successes: Being able to utilize command line knowledge from priort experience with UNIX and Linux helped.

Setbacks: At first, the program was struggling to properly run the parent at all. It would continue to wait, despit ethe child process finishing.

Learned: how forking a process works, the relationship between a child and parent process


/*
Commands:
gcc sshell.c -o sshell
./sshell 

Output:
osh>
*/

- Started from in-class base code
