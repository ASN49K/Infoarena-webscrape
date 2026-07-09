#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b)
{
	while(b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

ifstream in("fisier.in");

int main()
{
	int t, a, b;
	in >> t;
	
	while(t--)
	{
		in >> a >> b;
		cout << euclid(a, b) << '\n';
	}
	
	return 0;
}