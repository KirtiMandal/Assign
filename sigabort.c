#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void abort_handler(int);

void main(){
	if(signal(SIGABRT,abort_handler)==SIG_ERR){
		fprintf(stderr,"Could not set signal handler\n");
		exit(1);
	}
	
	abort();
	exit(1);
}

void abort_handler(int i){

	fprintf(stderr,"Caught SIGABRT, exiting application\n");
	exit(1);
}
