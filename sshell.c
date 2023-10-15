/// @file sshell.c
/// @brief - Serves as a shell interface that accepts user commands.
/// @author Tyler Edwards - tk.edwards2003@gmail.com

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LINE 80 

int main(void)
{
    char *args[MAX_LINE/2 + 1];
    int should_run = 1;
    pid_t pid;

    while(should_run)
    {
        printf("osh>");
        fflush(stdout);

        char input[100];

        fgets(input, sizeof(input), stdin);

        size_t size = strlen(input);
        if (size > 0 && input[size - 1] == '\n')
        {
            input[size - 1] = '\0';
        }

        int i = 0;
        char *token = strtok(input, " ");
        //printf("%s\n", args[0]);

        while (token != NULL && i < MAX_LINE/2)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
            //printf("%s\n", args[i]);
        }
        args[i] = NULL;

        pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Fork Failed");
            fflush(stdout);
            should_run = 0;
        }

        else if(pid == 0)
        {
            execvp(args[0], args);
            exit(0);
        }

        else
        {
            //printf("I am the parent.");
            bool check = true; 
            char find = '&';
            int numStrings = i;

            for(int j = 0; j < numStrings; ++j)
            {
                char *arg = args[j];
                while(*arg != '\0')
                {
                    if(*arg == find)
                    {
                        check = false;
                        break;
                    }
                    arg++;
                }
            }

            if(check)
            {
                //printf("I am waiting.");
               wait(NULL); 
            }
        }

    }

    return 0;
}