#include<iostream>
using namespace std;

template <typename T>
T swapp(T n1,T n2){
	T temp;
	temp=n1;
	n1=n2;
	n2=temp;
	cout<<"After swap value 1st value is-> "<<n1<<" and second value is-> "<<n2<<endl<<endl;
}
	
int main(){
	int A=10,B=20;
	char a[10]="kirti",b[10]="mandal";
	double x=20,y=200;

	cout<<"Before swap value of 1st is-> "<<A<<" and 2nd is-> "<<B<<endl;
	swapp(A,B);
	cout<<"Before swap value of 1st is-> "<<a<<" and 2nd is-> "<<b<<endl;
	swapp(a,b);
	cout<<"Before swap value of 1st is ->"<<x<<" and 2nd is ->"<<y<<endl;
	swapp(x,y);

return 0;

}
