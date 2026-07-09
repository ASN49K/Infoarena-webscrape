#include<fstream>
using namespace std;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int a[1024],b[1024],m,n,k,i,j,v[1024],c=0;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	k=1;
	for(i=1;i<=n;i++)
	{
		for(j=k;j<=m;j++)
			if(a[i]==b[j])
			{
				c++;
				v[c]=b[j];
				k=j;
			}
	}
	g<<c<<'\n';
	for(i=1;i<=c;i++)
		g<<v[i]<<' ';
	f.close();
	g.close();
	return 0;
}

	