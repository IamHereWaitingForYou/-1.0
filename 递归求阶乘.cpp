#include<iostream>
using namespace std;
int Ser(int n)
{
	if(n<=2)
	return n;
	else
	return n*Ser(n-1);
}
int main()
{
	int n;
	cin>>n;
	cout<<Ser(n);
	return 0;
}
