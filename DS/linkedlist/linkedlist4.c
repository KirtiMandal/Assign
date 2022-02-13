#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int info;
struct node* link;
}node;


node *head=0;
void atEnd(node *head,int info){
node *ptr,*temp;
ptr=head;
temp=(node*)malloc(sizeof(struct node));

temp->info=info;
temp->link=NULL;

while(ptr->link!=NULL){
ptr=ptr->link;
}
ptr->link=temp;
}

void print(node *ptr){
while (ptr!=NULL){
printf("%d",ptr->info);
ptr=ptr->link;
if(ptr!=NULL){
}
}
}

int main(){
print(head);
atEnd(head,10);
print(head);
return 0;
}
