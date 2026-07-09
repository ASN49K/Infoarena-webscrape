#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	int T,a,b,i,r;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>a>>b;
		while(a%b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		cout<<b<<endl;
	}
	return 0;
}