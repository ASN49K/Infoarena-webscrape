#include <stdio.h>
#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;

	while(b)
	{
		int r=a%b;
		a=b;
		b=r;
	}

	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	int T,a,b;

	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		cout<<gcd(a,b)<<'\n';
	}

	return 0;
}

