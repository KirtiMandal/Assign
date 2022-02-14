#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main(){

	int i=0,j=0,l;
	char lstr[101];
	printf("Enter a lower case string\n");
	scanf("%s",lstr);
	l=sizeof(lstr);
	for (i=l;i>=0;i--){
		if (lstr[i]==lstr[i+1]){
			int j=i;
			while (lstr[j]!='\0'){
			lstr[j]=lstr[j+2];
			j++;
			}
		}
	}
	if (lstr[0]=='\0')
	printf("Empty String\n");
	else
	printf("Here is your resultant string : %s\n",lstr);
}

