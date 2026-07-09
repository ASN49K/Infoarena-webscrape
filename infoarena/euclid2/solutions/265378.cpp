#include<fstream.h>
int gcd(long int x,long int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

int main()
{
	long int a,b,t;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>t;
	while(t!=0)
	{
		fin>>a>>b;
		fout<<gcd(a,b);
		t--;
	}
	return 0;
}