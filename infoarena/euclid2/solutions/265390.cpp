#include<fstream.h>
int a,b,t;
int gcd(int x,int y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

int main()
{
	
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