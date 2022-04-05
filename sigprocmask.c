#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void printSignalSet(sigset_t *set){
	const int siglist[]={SIGHUP,SIGINT,SIGQUIT,SIGABRT,SIGILL,SIGKILL,SIGSEGV,SIGFPE};
	const char *sigNames[]={"SIGHUP","SIGINT","SIGQUIT","SIGABRT","SIGILL","SIGKILL","SIGSEGV","SIGFPE"};
	const int siglen=8;
	
	for(int i=0;i<siglen;i++){
		int ret=sigismember(set,siglist[i]);
		if(ret==-1){
			perror("sigismember:");
			exit(EXIT_FAILURE);
		}
		else if(ret==0) {
			printf("Signal %s=%d is in the set\n",sigNames[i],siglist[i]);
		}
		else {
			printf("Signal %s=%d is not in the set\n",sigNames[i],siglist[i]);
		}
	}
} 
		
int main(void){
	sigset_t set;
	if(sigprocmask(0,NULL,&set)!=0){
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	printf("---Initial signal mask for this process----\n");
	printSignalSet(&set);
	
	if(sigaddset(&set,SIGINT)!=0){
		perror("sigaddset:");
		exit(EXIT_FAILURE);
	}
	
	if(sigprocmask(SIG_SETMASK,&set,NULL)!=0){
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	printf("----New signal mask for this process----\n");
	printSignalSet(&set);
	
	int setToSleep=5;
	printf("Try CTrl+C to kill this program with kill -kill %d. Going to sleep for %d seconds\n",getpid(),setToSleep);
	sleep(setToSleep);
	printf("Sleep returned\n");
	
	printf("Removing all signals from mask\n");
	sigemptyset(&set);
	sigfillset(&set);
	//sigprocmask(SIG_SETMASK,&set,NULL);
	
	printSignalSet(&set);
	
	sleep(1);
	printf("Exited normally\n");
	
	return 0;
}
