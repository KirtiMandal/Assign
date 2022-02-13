#include<stdio.h>
 

int main(){

	unsigned int n;
	int i=0,r,count=0;
	int a[32];
	scanf("%d",&n);

	while (n!=0){
		r=n%2;
		n=n/2;
		a[i]=r;
		i++;
		count++;
	}
	for (i=0;i<=count-1;i++){
		printf("%d",a[i]);
	}
	printf("\n");
return 0;
}

