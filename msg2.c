#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>
#define MAX_TEXT 512
//#define BUFSIZ 100
struct my_msg_st
{
        long int type;char some_text[MAX_TEXT];
};
int main()
{
        int running=1;int msgid;struct my_msg_st some_data;
        char buffer[BUFSIZ];
        msgid=msgget((key_t)1234,0666|IPC_CREAT);
        if(msgid==-1)
        {
                fprintf(stderr,"failed to create:\n");
                exit(EXIT_FAILURE);
        }
     //   while(running)
      //  {
                printf("\nEnter some text:");
                fgets(buffer,BUFSIZ,stdin);
                some_data.type=1;
                strcpy(some_data.some_text,buffer);
                if(msgsnd(msgid,(void*)&some_data,MAX_TEXT,0)==-1)
                {
 fprintf(stderr,"failed to send:\n");
                exit(EXIT_FAILURE);
                }
                if(strncmp(buffer,"end",3)==0)
                        running=0;
        //}
        exit(EXIT_SUCCESS);
        return 0;
}
