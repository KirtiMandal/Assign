#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

Network understands big endian or network byte order.
int main(){
	char *serv_ip="127.0.0.1";
	int sockfd,retval;
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(8000);
	inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);
	
	retval=connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
	if(retval<0){
		perror("connect: ");
		exit(1);
		}
	printf("client established connection with server\n");
	close(sockfd);
	return 0;
}
