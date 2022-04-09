#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

//Network understands big endian or network byte order.
int main(){
	char *serv_ip="127.0.0.1";
	char *msg="shutup";
	int sockfd,retval;
	socklen_t addr_len;
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	if(sockfd<0){
		perror("error:");
		exit(1);
	}
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(8000);
	inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);
	addr_len=sizeof(struct sockaddr_in);
	
	retval=sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&servaddr,addr_len);
	printf("ret val of sendto = %d\n",retval);
	close(sockfd);
	return 0;
}
