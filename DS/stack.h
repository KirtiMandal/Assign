int push(char a[],int *t,char e,int n)
{
if (*t>=n)
{
printf("Stack overflow\n");
return 0;
}
else
{
*t=*t+1;
printf("top=%d\n",*t);
a[*t]=e;
printf("%c",a[*t]);
return 1;
}
}

char pop(char a[],int *t)
{
printf("%c",a[]);
if(*t==0){
printf("stack underflow\n");
return 0;
}
else {
*t=*t-1;
return a[*t+1];
}
}

char pip(char a[],int *t,int i)
{
if (*t-i+1<=0){
printf("stack overflow\n");
return 0;
}
else {
return a[*t-i+1];
}
}

int change(char a[],int *t,char e,int i){
if (*t-i+1<=0){
printf("stack underflow\n");
return 0;
}
else {
a[*t-i+1]=e;
return 1;
}
}

