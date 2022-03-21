#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//used this code to observe how we can find error in our code


int main()
{
int num;
do{
printf("Enter a member :");
scanf("%d",&num);
}while(num<0);

int fact=1;
for(int i=1;i<=num;i++){
fact=fact*i;
printf("%d! = %d\n",num,fact);}
return 0;	
}
