#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int var_glb; /* A global variable*/

int main(void)
{
    pid_t childPID;
    int counter = 0;

    childPID = 1;

    int i=0;
    do
    {
        if(childPID >= 0) // fork was successful
        {
            if(childPID == 0) // child process
            {
                sleep(500000);
            }
            else //Parent process
            {
                printf("Parent: %d, PID: %d\n", i, childPID);
                childPID = fork();
                // maybe do something
            }
        }
        else // fork failed
        {
            printf("\n Fork failed, quitting!!!!!!\n");
            return 1;
        }
        i++;
    } while (1);

    if (childPID != 0)
    {
        printf("Parent: %d, PID: %d\n", i, childPID);
    }

    return 0;
}
