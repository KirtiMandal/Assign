#include<iostream>
using namespace std;
template<class T1,class T2>

class sample
	{
	T1 a; T2 b;
	public:void getdata(){
	cout<<"Enter a and b"<<endl;
	cin>>a>>b;	
	}
	void display(){
	cout<<"The values are"<<endl;
	cout<<"a: "<<a<<"\nb: "<<b<<endl;
	}
	};

int main()
{
sample <int,int> s1;
sample <int ,double> s2;
sample <double, double> s3;
cout<<"Integer data: "<<endl<<endl;
s1.getdata();
s1.display();
cout<<"Int and double data : "<<endl<<endl;
s2.getdata();
s2.display();
cout<<"double and double data : "<<endl<<endl;
s3.getdata();
s3.display();

return 0;

}

	

