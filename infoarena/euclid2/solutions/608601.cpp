#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned int t,i,a,b,r;
int main()
{
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<'\n';
	}
	return 0;
}
