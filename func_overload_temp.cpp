#include<iostream>
using namespace std;

template<class t1>
void sum(t1 a,t1 b,t1 c){
cout<<"Sum : "<<a+b+c<<endl;
}

template<class t1,class t2>
void sum(t1 a,t2 b,t1 c){
cout<<"Sum : "<<a+b+c<<endl;
}

void sum(int a,int b){
cout<<"Sum : "<<a+b<<endl;
}


int main()
{
int a=1,b=2;
float x=2.2,y=1.1,z=3.3;
cout<<"Values of variables are: "<<a<<"\t" << b<<"\t" << x<<"\t" << y<<"\t" << z<<"\t" <<endl;
sum(x,y,z);
sum(a,b);
sum(a,x,b);

return 0;	
}
