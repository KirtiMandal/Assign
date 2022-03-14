#include<iostream>
#include<exception>
using namespace std;

class Base{
public:
int x;
int ip1(int x){
cin>>x;
}
};

class Derived:public Base{
	public:
	int y;
	int ip(int y){
	cin>>y;
	}
};

int main(){
	int x,y;

	Derived b;
	Derived a;
	
	a.ip1(x);
	b.ip(y);

	cout<<"First number should be greater then second to get exception"<<endl;

	try{
		if(x>y) 
		throw Derived();
		else
		cout<<"No exception"<<endl;
	}

	catch(Derived d){
		cout<<"Derived object caught"<<endl;
	}

	catch(Base b){
		cout<<"Base object caught"<<endl;
	}


return 0;
}
