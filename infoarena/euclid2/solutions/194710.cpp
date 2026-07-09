#include<fstream.h>

int y(int a)
{
	if (a<2)
	return 0;
	if (a==2)
	return 1;
	if (a%2==0)
	return 0;
	for (int i=0;i*i<a;i++)
	{
		if (a%i==0)
		return 0;
	}
	return 1;
}
int x(int a, int b)
{
	int i=0,cmmdc=1;
	for (i=0;i<a && i<b;i++)
		if (y(i)==1)
		{
		 while (a%i==0 & b%i==0)
		{
		cmmdc=cmmdc*i;
		}
		}
	return cmmdc;
}	


int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long t;
	fin>>t;
	int i=0,k,l;
	for (i=0;i<t;i++)
	{
		fin>>k>>l;
		fout<<x(k,l)<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}