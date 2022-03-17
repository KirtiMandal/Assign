#include<iostream>
using namespace std;

template<typename T,typename U>

auto add(T a,U b)->decltype(a+b){
return a+b;
}

int main(){
//int a;
//char b[1];
//float c;
auto d=0;
//cout<<"Input integer char and float"<<endl;
//cin>>a>>b>>c;
d=add(3,4.5);
cout<<"In the function : "<<d<<endl;
d=add(3,6);
cout<<"In the function : "<<d<<endl;
d=add(3,'A');
cout<<"In the function : "<<d<<endl;	
return 0;
}
