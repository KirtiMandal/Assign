#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

void handleClient(int commfd){
	int n;
	char buf[200];
	n=read(commfd,buf,200);
	buf[n]='\0';
	printf("Data rec'd from client = %s\n",buf);
	printf("Request handled by the server %d\n",getpid());
	write(commfd," Tata byebye khatam ",20);
	exit(0);
}

int main(){
	int listfd,commfd,retval;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;
	
	listfd=socket(AF_INET,SOCK_STREAM,0);
	if(listfd < 0){
		perror("sock : ");
		exit(1);
	}
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(8000);
	
	retval=bind(listfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(retval<0){
		perror("bind : ");
		exit(2);
	}
	
	listen(listfd,5);
	
	while(1){
		char  buf[200];
		pid_t p;
		int n;
		clilen=sizeof(cliaddr);
		commfd=accept(listfd,(struct sockaddr*)&cliaddr,&clilen);
		printf("client connected\n");
		p=fork();
		if(p==0){
			close(listfd);
			handleClient(commfd);
		}
		close(commfd);
	}
}
