#include<stdio.h>
#include "my_calc.h"

int main(){
int a,b;
scanf("%d %d",&a,&b);
printf("Addition : %d\n",add(a,b));
printf("Subs : %d\n",sub(a,b));
printf("Div : %d\n",div(b,a));
printf("Mul : %d\n",mul(a,b));


}
