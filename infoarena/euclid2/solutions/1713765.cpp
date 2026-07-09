//http://www.infoarena.ro/problema/euclid2
#include <iostream>
using namespace std;
int main()
{
	int l,a,b,r,k;
	cin>>l;
	for(k=1;k<=l;k++)
	{
		cin>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		cout<<b<<'\n';
	}
	return 0;
}
