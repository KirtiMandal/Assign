#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

int main(){
	char *p;
	int id;
	id =shmget(48,200,IPC_CREAT|0644);
	
		if(id<0){
		perror("Shmget");
		return 0;
		}

	printf("id=%d\n",id);
	p=shmat(id,0,0);
	printf("Data read:\n");
	printf("%s\n",p);
	return 0;
}
