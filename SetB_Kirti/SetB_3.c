#include<stdio.h>
 
void reverseBits();
void binaryForm();

int i=0,r,count=0;
int a[32];
int main(){

	unsigned int n;
	scanf("%d",&n);

	while (n!=0){
		r=n%2;
		n=n/2;
		a[i]=r;
		i++;
		count++;
	}
	printf("Binary value of the integer number is :\n");
	binaryForm();
	printf("\n");

	printf("After reversing the bit value :\n");
	reverseBits();
	printf("\n");
return 0;
}

void reverseBits(){
for (i=0;i<=count-1;i++){
		printf("%d",a[i]);
	}
}

void binaryForm(){
for (i=count-1;i>=0;i--){
		printf("%d",a[i]);
	}
}

