#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

union semnum{
		int val;
		struct sid_ds *buf;
		unsigned short *array;
		struct seminfo *_buf;
	};
	
int get_released(void);
int get_semaforce(void);
struct sembuf sem_op;
union semnum sem_union;
int sid;

int main(){
	int i;
	sleep(3);
	
	sid=semget((key_t)10,1,0666|IPC_CREAT);
	printf("\nsemaforce ID : %d\n",sid);
	
	sem_union.val=1;
	if(semctl(sid,0,SETVAL,sem_union)<0){
		printf("Error");
	}
	
	for(i=0;i<=5;i++){
		get_semaforce();
		printf("\n%d : Got the seamforce\n",getpid());
		sleep(1);
		printf("\n%d : Released the semaforce\n",getpid());
		get_release();
		sleep(1);
	}
	
	if(semctl(sid,0,IPC_RMID,sem_union)<0)
		printf("Fails to delete the semaforce\n");
		
	else 
		printf("Semaforce deleted\n");
}

int get_semaforce(void){
		sem_op.sem_num=0;
		sem_op.sem_op=-1;
		sem_op.sem_flg=SEM_UNDO;
		
	if(semop(sid,&sem_op,1)<0){
		printf("Failed\n");
		return -1;
		}
}

int get_release(void){
		sem_op.sem_num=0;
		sem_op.sem_op=1;
		sem_op.sem_flg=SEM_UNDO; //It is applied to semaphore 2nd 						arguement sembuf i.e a structure
//Kernel will read SEM_UNDO and know what changes have been done to the semaphore by the process. If process terminated without releasing semphore, SEM_UNDO will allow to automatically release semaphore.
	
	
	if(semop(sid,&sem_op,1)<0){
		printf("Failed\n");
		return -1;
		}
}
