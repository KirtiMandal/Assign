#include<iostream>
#include<exception>
using namespace std;
void exptn(int a){
if(a>10) throw a;
}
int main(){
int a;
	try{
		int* myarray=new int[100];
	exptn(11);
	}
		
	catch(exception &e){
		cout<<"Std exception"<<e.what()<<endl;
	}
		
return 0;
}


