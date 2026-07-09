#include<iostream.h>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	int i,T,a,b,r;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>a>>b;
		r=a%b;
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