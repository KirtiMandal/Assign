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
		struct seminfo *__buf;
	};
	
int released_semaphore(void);
int get_semaphore(void);
struct sembuf sem_op;
union semnum sem_union;
int sem_id;

int main(){
	int i,j;
	sem_id=semget((key_t)1234,1,0666|IPC_CREAT);
	
	for(i=0;i<=10;i++){
		get_semaphore();
		printf("\n%d : Got the seamforce\n",getpid());
		for(j=0;j<=3;j++){
		sleep(1);
		printf("\a");
	 }
		printf("\nSEM@: %d released the semaphore\n",getpid());
		release_semaphore();
		sleep(2);
		
	}
	
	if(semctl(sem_id,0,IPC_RMID,sem_union)<0)
		printf("Fails to delete the semaphore\n");
		
	else 
		printf("Semaphore deleted\n");
}

int get_semaphore(void){
		sem_op.sem_num=0;
		sem_op.sem_op=-1;
		sem_op.sem_flg=SEM_UNDO;
		
	if(semop(sem_id,&sem_op,1)<0){
		printf("Failed\n");
		return -1;
		}
}

int release_semaphore(void){
		sem_op.sem_num=0;
		sem_op.sem_op=1;
		sem_op.sem_flg=SEM_UNDO;
	if(semop(sem_id,&sem_op,1)<0){
		printf("Failed\n");
		return -1;
		}
}
