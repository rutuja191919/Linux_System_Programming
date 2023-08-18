#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>

#define MAX_SIZE 512

struct my_msg_st
{
    long int my_msg_type;
    char text[MAX_SIZE];
};

int main()
{
    int running = 1;
    struct my_msg_st str;
    int msgid = 0;
    char buffer[BUFSIZ];

    msgid = msgget((key_t)1234,0666 | IPC_CREAT);

    if(msgid == -1)
    {   
        fprintf(stderr, "Failed to create\n");
        exit(EXIT_SUCCESS);
    }

    while(running)
    {
        printf("Enter some text : ");
        fgets(buffer, BUFSIZ, stdin);
        str.my_msg_type = 1;
        strcpy(str.text, buffer);

        if(msgsnd(msgid, (void *)&str, MAX_SIZE, 0) == -1)
        {
            fprintf(stderr, "msgng failed\n");
            exit(EXIT_SUCCESS);
        }
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
}