#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b,t,r;
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	cin >> t;
	for(;t;t--)
	{
		cin >> a>> b;
		while(b)
		{ 
			r=a%b;
			a=b;
			b=r;
		}
		cout << a <<endl;
		
	}
	return 0;
	}
	

