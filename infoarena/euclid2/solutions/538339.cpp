#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a[1000],b[1000],i;
void citire()
{
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>a[i]>>b[i];
}
void divizor(int a, int b)
{
	int r;
	r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	fout<<b<<'\n';
}
int main()
{
	citire();
	for(i=1;i<=n;i++)
	{
		divizor(a[i],b[i]);
		
	}
	return 0;
}
