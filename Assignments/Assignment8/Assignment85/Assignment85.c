#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp= NULL;
    int process_id = 0;
    int sid = 0, i = 0;
    
    // Create child process
    process_id = fork();
    
    // Indication of fork() failure
    if(process_id == 0)
    {
        printf("Child process running\n");
    }

    else if(process_id > 0)
    {
        printf("Child process with id :  %d \n", process_id);
        exit(0); //Terminate the parent process successfully to make child as daemon process
    } 

    else
    {
        printf("fork failed!\n");
        exit(1);
    }
   
    //unmask the file mode
    umask(0);   //Since, the newly created daemon process should be able to open, read and write any file anywhere, lets un-mask any file modes it has inherited as defaults. Thereby, we give all the file rights to the daemon process through the unmask call.
    
    //set new session
    sid = setsid();
    if(sid < 0)
    {
    // Return failure
    exit(1);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //Daemon process logic
    fp = fopen ("mydaemonfile.txt", "w+");
    while (i < 20)
    {
        sleep(1);
        fprintf(fp, "%d", i);
        i++;
    }
    fclose(fp);
    
    return 0;
}