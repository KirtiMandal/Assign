#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
	int fd;
	char *c;
	struct stat file_info;
 	fd=open("kernel.txt",O_CREAT|O_RDWR,0777);
	write(fd,"linux kernel technologies");
	fstat(fd,&file_info);
	printf("File size is %d\n",file_info.st_size);

	c=mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	perror("mmap");

	strcpy(c,"linuxkernel");
	printf("%s\n",c);
	munmap(c,50);
return 0;
}

