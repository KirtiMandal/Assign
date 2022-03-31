#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

typedef struct{
	 long msgtype;
	 char buffer[40];
}msg;

int main(int argc,char **argv[]){
	int qid ;
	msg m1;
	qid=msgget(32,IPC_CREAT||0644);
	msgrcv(qid,&m1,sizeof(msg),atoi(argv[1]),0);
	printf("%s",m1.buffer[40]);
	printf("\n");

 return 0;
}
