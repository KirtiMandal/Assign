#include<stdio.h>
#include<stdlib.h>
void main(){
struct node {
int data;
struct node *info;
};

struct node *head,*newnode,*temp;
head=(struct node*) malloc(sizeof(struct node));
int choice;
newnode=(struct node*) malloc(sizeof(struct node));
printf("Enter the number\n");
scanf("%d",&head->data);
newnode->info=0;

//while (choice==1){
if (head==0)
{
head=newnode;
}
else
{
temp->info=newnode;
temp=newnode;
}
printf("do u want to add more nodes?(0/1)");
scanf("%d",&choice);

temp=head;
while(temp!=0){
printf("%d",temp->data);
temp=temp->info;
}
getch();
}







