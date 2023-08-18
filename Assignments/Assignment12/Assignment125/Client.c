#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>

struct my_msg_st
{
    long int my_msg_type;
    char text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgid = 0;
    struct my_msg_st str;
    long int msg_to_receive = 0;

    msgid = msgget((key_t)1234,0666 | IPC_CREAT);

    while(running)
    {
        msgrcv(msgid, (void*)&str, BUFSIZ, msg_to_receive, 0);

        printf("You wrote : %s", str.text);
        if(strncmp(str.text,"end",3) == 0)
        {
            running = 0;
        }
    }

    exit(EXIT_SUCCESS);

}
