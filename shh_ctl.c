#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

int main(){
	int shmid;
	struct shmid_ds buf;
	shmid=shmget(48,250,IPC_CREAT|0644);
	printf("shmid : %d\n",shmid);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
