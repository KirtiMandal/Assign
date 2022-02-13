#include<stdio.h>
#include<stdlib.h>

//Inserting a node in a linkedlist

typedef struct node{
int info;
struct node *link;
}node;

void main(){
node *head=malloc(sizeof(node));
head->info=20;
head->link=NULL;
add_end(head,50);
add_end(head,5);

int info=90,i=3;
new_i(head,info,i);
node *ptr=head;

while(ptr!=NULL)
{
printf("%d",ptr->info);
ptr=ptr->link;
}
}

void new_i(struct node *head,int info,int i)
{
node *ptr=head;
node *ptr2=malloc(sizeof(node));
ptr2->info=info;
ptr2->link=NULL;

i--;
while(i!=1)
{ptr=ptr->link;
i--;
}
ptr2->link=ptr->link;
ptr->link=ptr2;
}

void add_end(struct node *head,int info){
node *ptr,*temp;
ptr=head;
temp=(struct node*)malloc(sizeof(struct node));

temp->info;
temp->link=NULL;

while(ptr->link !=NULL){
ptr=ptr->link;
}
ptr->link=temp;
}

