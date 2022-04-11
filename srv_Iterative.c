#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>

#define PORT 8000
#define MAXSZ 100

int main(){
	int sockfd,newsockfd;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;

	int n;
	char msg[MAXSZ];
	int cliaddrlen;
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	memset(&servaddr,0,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//taking char string and converting into 32 bit network byte order. Opposite of this is ntoa()
	servaddr.sin_port=htons(PORT);
	
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	listen(sockfd,5);
	
	while(1){
		printf("\nServer waiting for new client connection\n");
		cliaddrlen=sizeof(cliaddr);
		newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&cliaddrlen);	
		
			while(1){
				n=recv(newsockfd,msg,MAXSZ,0);
				if(n==1){
					close(newsockfd);
				break;
				}
				msg[n]=0;
				send(newsockfd,msg,n,0);
				
				printf("Receive and set %s\n",msg);
	}
}
//close(listfd);
return 0;
}
