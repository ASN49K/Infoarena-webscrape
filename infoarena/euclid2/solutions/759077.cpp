#include<iostream>

using namespace std;

int main()
{
	int m,n,r;
	cin>>m;
	cin>>n;
	while(r!=0)
	{
		r=m%n;
		if(r==0) cout<<n;
		else { m=n;
		       n=r;}
	}
	return 0;
}
	