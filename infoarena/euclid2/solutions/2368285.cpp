#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
	if(a==0)
		return b;
    else
        if(b==0)
            return a;
        else
            if(a>b)
                return euclid(a%b,b);
            else
                return euclid(a,b%a);
}

int main()
{
	int n,i,a,b;

	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		fout<<euclid(a,b)<<'\n';
	}
	return 0;
}
