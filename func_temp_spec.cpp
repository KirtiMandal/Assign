#include<iostream>
using namespace std;

template<class x>
void swapp(x &a,x &b){
x temp;
temp=a;
a=b;
b=temp;
cout<<"Inside template swap\n";
}

void swapp(int &a,int &b){
int temp;
temp=a;
a=b;
b=temp;
cout<<"Inside int swap:"<<endl;

}


int main()
{
int a=5,b=10;
double x=1.1,y=2.2;
char i='x',j='y';
cout<<"Before swap: "<<a<<"\t"<<b<<endl;
swapp(a,b);
cout<<"After swap: "<<a<<"\t"<<b<<endl<<endl;
	
cout<<"Before swap: "<<x<<"\t"<<y<<endl;
swapp(x,y);
cout<<"After swap: "<<x<<"\t"<<y<<endl<<endl;

cout<<"Before swap: "<<i<<"\t"<<j<<endl;
swapp(i,j);
cout<<"After swap: "<<i<<"\t"<<j<<endl<<endl;

return 0;
}
