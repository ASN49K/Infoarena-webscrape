#include<iostream>
using namespace std;
int main()
{
	int a,b,r,s;
	cin>>a;
	cin>>b;
	if(b>a)
	{
		s=a;
		a=b;
		b=s;
	}
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	cout<<a;
	return 0;
}