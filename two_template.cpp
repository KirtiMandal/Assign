#include<iostream>
using namespace std;

template <typename T1,typename T2>
T2 sum(T1 n1,T2 n2){
	T2 rs;
	rs=n1+n2;
	return rs;
	}
	
int main(){
int A=10,a=20,C;
float B=11.5,b=22.6,c;
C=sum(A,B);
cout<<"the sum of int : "<<C<<endl;
c=sum(a,b);
cout<<"The sum of float is : "<<c<<endl;
return 0;

}
