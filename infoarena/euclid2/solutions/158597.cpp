#include<fstream.h>
int cmmdc(long a,long b);
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long a,b,n;
	fin>>n;
	for (int i=0;i<n;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b);
	}
fin.close();
fout.close();
	return 0;
}
int cmmdc(int a,int b)
{
	if (a==0)
	return b;
	if (b==0)
	return a;
	while (a!=b)
	{
		if(a>b)
		a=a-b;
		if(b>a)
		b=b-a;
	}
	return a;
}