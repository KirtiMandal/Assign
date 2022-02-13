#include<stdio.h>
#include<stdlib.h>

//insert a node at the begining 

typedef struct node{
int info;
struct node *link;
}node;

struct node* head;

void insert(int info){
node* newnode=(node*)malloc(sizeof(struct node*));
newnode->info=info;
newnode->link=head;
head=newnode;
}

void new(){
node* h;
h=head;

while(h!=NULL){
printf("%d\n",h->info);
h=h->link;
}
}
int main(){
head=NULL;
insert(50);
insert(64);
new();
return 0;
}

