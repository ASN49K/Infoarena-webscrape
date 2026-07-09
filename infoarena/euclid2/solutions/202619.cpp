#include<fstream.h>
long t,a,b;
ofstream fout("euclid2.out");

long cmmdc(long x, long y)
{
	long r;
	do{
			r=x%y;
			x=y;
			y=r;
		}while (r!=0);
	return x;
}



void afisare(long d)
{
	fout<<d<<'\n';
}



void citire()
{
	ifstream fin("euclid2.in");
	fin>>t;
	for(int i=1;i<=t;i++)
		{
			fin>>a>>b;
			afisare(cmmdc(a,b));
		}
}


int main()
{
	citire();
	fout.close();
	return 0;
}