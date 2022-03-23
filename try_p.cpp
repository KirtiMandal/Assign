#include<iostream>
#include<vector>
using namespace std;

int main(){
vector <char> v(10);
vector <char>::iterator p,p1,p2;
int i;
p=v.begin();
i=0;
while(p!=v.end()){
	*p=i+'a';
	p++;
	i++;
}
cout<<"Original contents :\n";
p=v.begin();
while(p!=v.end()){
cout<<*p<<" ";
p++;}

p=v.begin();
while(p!=v.end()){
*p=toupper(*p);
p++;}

cout<<"\nModified contents: \n";
p=v.begin();
while(p!=v.end()){
cout<<*p<<" ";
p++;}
cout<<"\n";

v.insert(p,4,'z');
p1=v.begin(2);
p2=v.begin(7);
erase(p1,p2);
cout<<*p<<endl;
p=v.begin();
while(p!=v.end()){
cout<<*p<<" ";
p++;}
cout<<"\n";
}
