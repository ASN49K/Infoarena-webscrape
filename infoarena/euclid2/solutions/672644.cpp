#include <fstream>
using namespace std;
fstream fin("euclid2.in",ios::in),fout("euclid2.out",ios::out);
int cmmdc(int i,int d)
{
	int r;
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
	int n,a,b,i;
	fin>>n;
	for (i=1;i<=n;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
