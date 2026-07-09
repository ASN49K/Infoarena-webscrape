#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
	int n,m;
	int t;
	fstream f("euclid2.in");
	fstream F("euclid2.out");
	f>>t;
	for(int i=1;i<=t;++i)
	{
		f>>n;f>>m;	
		while (n!=m) if(n>m) n-=m;
					 else m-=n;
		F<<(n)<<'\n';
	}	
	return 0;
}
