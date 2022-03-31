#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

typedef struct{
	 long msgtype;
	char buffer[40];
}msg;

int main(){
	int qid ;
	msg m1;
	qid=msgget(32,IPC_CREAT||0644);
	printf("Id = %d\n",qid);
	m1.msgtype=atoi(argv[1]);
	strcpy(m1.buffer,argv[2]);
	msgsnd(qid,&m1,strlen(m1.buffer)+1,0);
 return 0;
}
