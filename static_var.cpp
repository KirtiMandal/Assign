#include<iostream>

using namespace std;

template<typename t>
void fun(const t &x){
static int i=10;
cout<<++i<<endl;
return;
}

int main()
{
fun<int>(1);
fun<int>(2);
fun<int>(5);
fun<double>(10.1);
//cout<<i;
return 0;	
}
