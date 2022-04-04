#include<stdio.h>
#include<signal.h>

void signhand(int signum){
	printf("Interrupt");
	signal(SIGINT,SIG_DFL);
}

int main(){
	int i;
	signal(SIGINT,signhand);
	
	for(i=0;;i++){
	printf("%d\n",i);
	sleep(1);
	}
	
}
