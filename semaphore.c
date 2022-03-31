#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define KEY (1492)

void main(){
	int id;
	union semun{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	}arguement;

	arguement.val=1;
	id = semget(KEY,1,0666|IPC_CREAT);
	
	if(id<0){
	fprintf(stderr,"Unable to obtain semaphore.\n");
	exit(0);
	}
	
	if(semctl(id,0,SETVAL,arguement)<0){
	fprintf(stderr,"Cannot set semaphore value \n");
	}
	
	else{
	printf("Semaphore %d initialized\nWith id = %d\n",KEY,id); 
	}
	
	
}
