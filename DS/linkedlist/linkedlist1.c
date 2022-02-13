#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int info;
struct node *link;
}node;

void display(node*);
node*insert(int, node*);
void main(){
node *first,*second,*third;
first=(node*)malloc(sizeof(node));
second=(node*)malloc(sizeof(node));
third=(node*)malloc(sizeof(node));

first->info=5;
first->link=second;

second->info=6;
second->link=third;

third->info=10;
third->link=NULL;

display(first);
}

void display(node *first)
{
node *save;
save=first;
while(save!=NULL){
printf("%d\n",save->info);
save=save->link;
}
}

node* insert(int x, node *first)
{
struct node *new;
new=(node*)malloc(sizeof(node));
new->info=x;
if(new==NULL)
{
printf("overflow");
}
else {
if (first=NULL){
new->link=NULL;
return new;
}
else {
new->link=first;
return new;
}
}
}



