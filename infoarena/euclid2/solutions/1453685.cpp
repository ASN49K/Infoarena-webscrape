#include <iostream>

using namespace std;

int dc(long long a, long long b)
{
	long long r=b;
	
	while(r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main ()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	int t;
	long long a,b;
	
	cin >> t;
	
	for (int i=0; i<t; i++)
	{
		cin >> a >> b;
		cout << dc(a,b) << endl;
	}
	
	
	
return 0;
}
