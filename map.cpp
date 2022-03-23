#include<iostream>
#include<map>
using namespace std;

int main(){
map<char,int> m;
int i;
for(i=0;i<26;i++){
m.insert(pair<char,int>('A'+i,65+i));
}
char ch;
cout<<"Enter key ,an uppercase letter"<<endl;
cin>>ch;

map<char,int>::iterator p;
p=m.find(ch);
if(p!=m.end())
cout<<"ASCII value for "<<p->first<<" is "<<p->second<<endl;
else
cout<<"Key not in map \n";

return 0;
}
