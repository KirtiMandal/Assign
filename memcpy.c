#include<stdio.h>
#include<string.h>

void copy(char* x,char* y,int count){
char x[30];
char y[30];
int i=0;
printf("Enter the string 1\n");
scanf("%s",x);
while(x[i]!='\0'){
y[i]=x[i];
i++;
}
printf("String 1 is %s\n" ,x);
printf("Copied string in string 2 is %s\n ",y);
}

int main(){
char str_1[30];
char str_2[30];
copy(str_1,str_2,strlen(str_1));

}


