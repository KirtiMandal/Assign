#include<stdio.h>
#include<string.h>

struct student{
int roll;
char name[40],gender;
float height;
}first;

int main(){
struct student second ;
struct student third={103,"Kirti Mandal",'F',5.4};

printf("\nRoll\t Name \t\t\t\t\t\t\t\t\tGender\tHeight\n");
first.roll=101;
strcpy(first.name,"Vidhi Sarogi");
first.gender='F';
first.height=5.4;
printf("\n%3d\t%-40s\t%c\t%1.2f\n",first.roll,first.name,first.gender,first.height);
printf("\n%3d\t%-40s\t%c\t%1.2f\n",third.roll,third.name,third.gender,third.height);

}
