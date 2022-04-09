#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

int main(){
	int sockfd,commfd,retval;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;
	char buf[10000];
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0){
		perror("sock : ");
		exit(1);
	}
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//taking char string and converting into 32 bit network byte order. Opposite of this is ntoa()
	servaddr.sin_port=htons(8000);
	
	retval=bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(retval<0){
		perror("bind : ");
		exit(2);
	}
	
	printf("Socket bound to port 8000\n");
	clilen=sizeof(struct sockaddr_in);
	
	while(1){
	int n;
		printf("Before rcvfrom\n");
		n=recvfrom(sockfd,buf,10000,0,(struct sockaddr *)&cliaddr,&clilen);
		printf("rec'd %d bytes \n",n);
		buf[n]='\0';
		printf("Data rec'd from client = %s\n",buf);
	}
//close(listfd);
}
