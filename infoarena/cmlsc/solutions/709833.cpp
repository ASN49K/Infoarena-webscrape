#include <fstream>
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
int ap[258];
int main()
{
	int v[300],i,l=0,x,y,cate=0,n,m;
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
	for (i=1;i<=257;i++)
	{
		if (ap[i]>1)
		{
			cate++;
			v[++l]=i;
		}
	}
	fout<<cate<<endl;
	for (i=1;i<=l;i++)
	{
		fout<<v[i]<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}
