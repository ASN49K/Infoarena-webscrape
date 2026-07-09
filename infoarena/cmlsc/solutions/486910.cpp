#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[100001],b[100001],m,n;
int main()
{
	int c[100001],i,j,k;
	fin>>n;
	fin>>m;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	k=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				if(a[i]>=c[k])
				{	k++;
					c[k]=a[i];
					fout<<c[k]<<' ';
				}
/*fout<<k<<'\n';
for(i=1;i<=k;i++)
	fout<<c[k]<<' ';*/
return 0;
}