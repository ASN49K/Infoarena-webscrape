#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T,a,b,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	cin >> T;
	for(;T;T--)
	{
		cin >> a >> b;
		while(b)
		{
			r = a%b;
			a = b;
			b = r;
		}
		cout << a << endl;
	}
	
	return 0;
}