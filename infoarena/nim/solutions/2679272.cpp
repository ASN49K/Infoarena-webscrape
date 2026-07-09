#include <bits/stdc++.h>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
	int t, n, x;
	in>>t;
	for(; t; t--)
	{
		in>>n;
		long long s=0;
		for(; n; n--)
		{
			in>>x;
			s^=x;
		}
		if(s)
			out<<"DA"<<'\n';
		else
				out<<"NU"<<'\n';
	}
}