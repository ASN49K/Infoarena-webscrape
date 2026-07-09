#include <fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
long long cmmdc(long long i,long long d)
{
	long long r;
	while (i>0)
	{
		r=d%i;
		d=i;
		i=r;
	}
	return d;
}
int main()
{
	long long n,a,b,i;
	fin>>n;
	for (i=1;i<=n;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
