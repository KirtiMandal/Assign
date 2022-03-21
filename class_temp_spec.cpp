#include<iostream>
using namespace std;

template <class T,int N>
class mySequence
{
	T memblock[N];
	public:
	void setMember(int x,T value);
	T getMember(int x);

};

template<class T,int N>
void mySequence<T,N>::setMember(int x,T value){
	memblock[x]=value;
}

template<class T,int N>
T mySequence<T,N>::getMember(int x){
	return memblock[x];}


int main()
{
const int a=5;
	mySequence<int,a> myints;
	mySequence<double,5> myfloats;
	myints.setMember(0,100);
	myfloats.setMember(3,3.14);
	cout<<myints.getMember(0)<<endl;
	cout<<myfloats.getMember(3)<<endl;
	return 0;
	
}
