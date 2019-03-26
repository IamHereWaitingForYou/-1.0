#include<iostream>
using namespace std;
int main()
{
	int jp[1010]={0,0,2,2};
	int n;
	for(int i=4;i<=1000;i++)
    {
    jp[i]=(jp[i-1]+jp[i-2]*2)%10000;
	}
	while(cin>>n)
    {
    if(n==0)
    return 0;
	cout<<jp[n]<<endl;
	}
}	 
