#include<iostream> 
class num 
{ 
public: 
num(int z=0,int m=0){numerator=z; denominator=m;} 
void yuefen(int x,int y);// ����Լ�ֺ���
num operator + (num n2);// ����� +���س�Ա����
num operator - (num n2);// ����� - ���س�Ա����
num operator * (num n2);// ����� *���س�Ա����
num operator / (num n2);// ����� / ���س�Ա����
bool operator == (num n2);// ����� ==���س�Ա����
double realnum()
{
	R=(double)numerator/denominator; 
	return R; 
	//cout<<R;
	}// ���庯������ת��
void show();// ���庯���������
private: 
int numerator,denominator; 
double R; 
}; 
void num::yuefen(int x,int y) // ����������
{ int t; 
int i; 
 if(x>y) 
 t=y; 
 else 
 t=x; 
 for(i=t;i>=1 ;i--) 
if((x%i==0)&&(y%i==0)) 
{ 
 t=i; 
 break; 
} 
if(t) 
{ 
numerator=x/t; 
denominator=y/t; 
} 
else 
{ 
numerator=x; 
denominator=y; 
} 
if(numerator==0) 
cout<<"0"<<endl; 
else 
cout<<numerator<<"/"<<denominator<<endl; 
} 
//////////////////////////////// ���������������ʵ�� /////////////////////////////////// 
num num::operator+(num n2) 
{ 
return 
num(numerator*n2.denominator+denominator*n2.numerator,
denominator*n2.denominator); 
} 
num num::operator-(num n2) 
{ 
return 
num(numerator*n2.denominator-denominator*n2.numerator,
denominator*n2.denominator); 
} 
num num ::operator*(num n2) 
{ 
return 
num(numerator*n2.numerator,denominator*n2.denominator)
; 
} 
num num ::operator/(num n2) 
{ 
return 
num(numerator*n2.denominator,denominator*n2.numerator)
; 
} 
bool num::operator == (num n2) 
{ 
if((numerator=n2.numerator)&&(denominator=n2.den
ominator)) 
return true; 
else 
return false; 
} 
void num::show()// ��ʾ�������
{ 
if(numerator==0) 
cout<<"0"<<endl; 
else if(denominator==0) 
cout<<" ������������ !"<<endl; 
else 
cout<<numerator<<"/"<<denominator<<endl; 
} 
/////////////////////////////////////////// ������ //////////////////////////////////// 
int main() 
{ 
char m; 
cout<<"/////////////////////////// ������������� //////////////////////////////"<<endl; 
cout<<" ȷ������ϵͳ�� (Y/N)"<<endl;// ��ʾ�Ƿ��������������ϵͳ
cin>>m; 
if(m=='n'||m=='N') 
cout<<" ������ϵͳ�� "<<endl; 
else if(m=='y'||m=='Y') 
{ 
char n; 
cout<<" ���������������� "; 
int a,b,c,d; 
cin>>a>>b>>c>>d; 
num n1(a,b),n2(c,d),n3; 
cout<<" ��������������� n1Ϊ��"; 
n1.show(); 
cout<<" ������ n1Ϊ��"; 
n1.yuefen(a,b); 
cout<<" ת �� Ϊ ʵ �� �� �� n1 Ϊ ��"<<n1.realnum()<<endl; 
cout<<" ��������������� n2Ϊ��"; 
n2.show(); 
cout<<" ������ n2Ϊ��"; 
n2.yuefen(c,d); 
cout<<" ת �� Ϊ ʵ �� �� �� n2 Ϊ ��"<<n2.realnum()<<endl; 
cout<<" ����������Ҫ��������� "; 
cin>>n; 
if(n=='+') 
{ 
n3=n1+n2; 
cout<<" ������Ĳ���Ϊ�� n1+n2="; 
n3.show(); 
cout<<" ��������Ϊ�� "; 
n3.yuefen(a*d+b*c,b*d); 
cout<<" ת �� Ϊ ʵ �� �� Ϊ ��"<<n3.realnum()<<endl; 
} 
else if(n=='-') 
{ 
n3=n1-n2; 
cout<<" ������Ĳ���Ϊ�� n1-n2="; 
n3.show(); 
cout<<" ��������Ϊ�� "; 
n3.yuefen(a*d-b*c,b*d); 
cout<<" ת �� Ϊ ʵ �� �� Ϊ ��"<<n3.realnum()<<endl; 
} 
else if(n=='*') 
{ 
n3=n1*n2; 
cout<<" ������Ĳ���Ϊ�� n1*n2="; 
n3.show(); 
cout<<" ��������Ϊ�� "; 
n3.yuefen(a*c,b*d); 
cout<<" ת �� Ϊ ʵ �� �� Ϊ ��"<<n3.realnum()<<endl; 
} 
else if(n=='/') 
{ 
n3=n1/n2; 
cout<<" ������Ĳ���Ϊ�� n1/n2="; 
n3.show(); 
cout<<" ��������Ϊ�� "; 
n3.yuefen(a*d,b*c); 
cout<<" ת �� Ϊ ʵ �� �� Ϊ ��"<<n3.realnum()<<endl; 
} 
else 
cout<<" ����������������ȷ�� "<<endl; 
cout<<" ��==���������֪�� "; 
if(a*d==b*c) 
cout<<"n1=n2"<<endl; 
else 
cout<<"n1!=n2"<<endl; 
} 
else 
cout<<" ������������ "<<endl; 
 cout<<" ����������������� (Y/N)";// ��ʾ�Ƿ��������
 char p; 
 cin>>p; 
if(p=='n'||p=='N') 
cout<<" �˳�����ϵͳ�� "<<endl; 
else if(p=='y'||p=='Y') 
return main(); 
else 
cout<<" ������������ "<<endl; 
return 0; 
}
