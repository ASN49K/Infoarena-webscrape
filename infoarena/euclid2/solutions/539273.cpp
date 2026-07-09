#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc,r,x,y,nr,a,b;
long t;
int main()
{
	fin>>t;
	fin>>x>>y;nr=1;
	while(nr<=t)
	{	
		a=x;b=y;
		r=x%y;
		while(r!=0)
		{
			x=y;
			y=r;
			r=x%y;
		}
		a=b;
		nr++;
		fout<<y<<'\n';
		fin>>x>>y;
	}
	return 0;
}
	