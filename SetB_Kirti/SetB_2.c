#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char name[10],str[20];
int count=0,cmp;

void main(){
	printf("Enter the persons name: \n");
	scanf("%s",name);

	FILE *fp;
	fp=fopen("file.txt","r");
	while (!feof(fp)){
		fscanf(fp,"%s",str);
		cmp=strcmp(str,name);
		if (cmp==0)
		count++;
	}
	printf("%d\n",count-1);
	fclose(fp);
}

