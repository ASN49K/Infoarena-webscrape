#include <fstream>
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
long long ap[261];
int main()
{
	long long v[300],i,l=0,x,y,cate=0,n,m;
	fin>>n>>m;
	for (i=1;i<=n;i++)
	{
		fin>>x;
		ap[x]++;
	}
	for (i=1;i<=m;i++)
	{
		fin>>y;
		ap[y]++;
	}
	for (i=1;i<=260;i++)
	{
		if (ap[i]>1)
		{
			cate++;
			v[++l]=i;
		}
	}
	fout<<cate<<"\n";
	for (i=1;i<=l;i++)
	{
		fout<<v[i]<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}
