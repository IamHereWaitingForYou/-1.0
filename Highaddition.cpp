#include<iostream>
#include<string>
using namespace std;
PP::Setin()
{
	cin>>a;
	cin>>b;
	PP c,d,w;
	c.len=a.length();
	d.len=b.length();
	for(int i=0;i<c.len;i++)c.num[c.len-1]=a[i]-'0';
	for(int i=0;i<d.len;i++)d.num[c.len-1]=b[i]-'0';
	
}
PP::Calute()
{
	w.len=max(c.len,d.len);
	for(int i=0;i<w.len;i++)
	{
		w.num[i]=a.num[i]+b.num[i];
		w.num[i+1]=w.num[i]/10;
		w.num[i]%=10;
	} 
	if(w.num[len+1]!=0)w.len++;
}

