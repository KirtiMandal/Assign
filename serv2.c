#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

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
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");//taking char string and converting into 32 bit network byte order. Opposite of this is ntoa()
	servaddr.sin_port=htons(8000);
	
	retval=bind(listfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(retval<0){
		perror("bind : ");
		exit(2);
	}
	
	listen(listfd,5);
	
	while(1){
		char buf[200];
		int n;
		clilen=sizeof(cliaddr);
		commfd=accept(listfd,(struct sockaddr*)&cliaddr,&clilen);
		printf("client connected\n");
		n=recvfrom(sockfd,buf,10000,0,(struct sockaddr *)&cliaddr,clzzilen);
		buf[n]='\0';
		printf("Data rec'd from client = %s\n",buf);
		write(commfd,"Good bye",8);
	}
close(listfd);
}
