using namespace std;
#include<iostream>
int main()
{
	int a,b,r;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	cin>>a>>b;
	r=a%b;
	while (r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	cout<<b;
	return 0;
}
