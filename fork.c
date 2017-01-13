#include <stdlib.h>

int main(void)
{
    pid_t childPID;
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
                childPID = fork();
            }
        }
        else // fork failed
        {
            return 1;
        }
        i++;
    } while (1);

    return 0;
}
