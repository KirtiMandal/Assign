#include<iostream>
#include<string.h>
#include<map>
using namespace std;

class name{
char str[40];
public:
name(){
strcpy(str,"");}
name (char*s){strcpy (str,s);}
char *get(){return str;}
};

bool operator <(name a,name b){
return strcmp(a.get(),b.get())<0;
}

class phoneNum{
char str[80];
public:
phoneNum(){
strcmp(str,"");
}
phoneNum(char *s){
strcpy(str,s);
}
char *get(){return str;}
};

int main(){
map<name,phoneNum> directory;
directory.insert(pair<name,phoneNum>(name("Kirti"),phoneNum("555-1006")));
directory.insert(pair<name,phoneNum>(name("Triyasha"),phoneNum("555-0306")));
directory.insert(pair<name,phoneNum>(name("Vidhi"),phoneNum("555-1610")));
directory.insert(pair<name,phoneNum>(name("Jhanvi"),phoneNum("555-1611")));

char str[80];
cout<<"Enter name : ";
cin>>str;
map<name,phoneNum>::iterator p;
p=directory.find(name(str));
if(p!=directory.end())
cout<<"Phone number : "<<p->second.get()<<endl;
else
cout<<"Name not in directory"<<endl;

return 0;
}
