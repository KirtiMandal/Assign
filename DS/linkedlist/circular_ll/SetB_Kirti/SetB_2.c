#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void removech(char * str,const char a,int i);

void main(){

	int i=0;
	char lstr[10],a;
	scanf("%s",lstr);

	while(lstr[i] != '\0'){
		if (lstr[i]==lstr[i+1]){
		a=lstr[i];
		removech(lstr,a,i+1);
		}
	}

	printf("%s ",lstr);

}

void removech(char * str,const char a, int i)
{
   // while(str[i] != '\0')
    //{
      //  if(str[i] == a)
        //{
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        //}
        //else
        //{
          //  i++;
        //}
    //}
}

