#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
		
	int a,b,T,r;
	
	cin >> T;
	for (;T;T--)
	{
		cin >> a >> b;
		while(b){r=a%b;a=b;b=r;}
		cout << a << "\n";
		
	}
	return 0;
}
