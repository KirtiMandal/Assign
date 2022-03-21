#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//used it to observe gdb


int main()
{
char *src;
src=malloc(100);
fgets(src,500,stdin);
printf("%s\n",src);
return 1;	
}
