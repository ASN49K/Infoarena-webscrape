#include<fstream.h>
int m,n,i,j,a[1025],b[1025],c[1025][1025],v[1025];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
int p=0;
f>>m>>n;
for (i=1;i<=m;i++) f>>a[i];
for (i=1;i<=n;i++) f>>b[i];
for (i=1;i<=m;i++)
	for (j=1;j<=n;j++)
		{
		if (a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
		else
			if (c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1];
			else c[i][j]=c[i-1][j];
		}
/*for (i=0;i<=m;i++)
	{if (i) cout<<endl;
	for (j=0;j<=n;j++) cout<<c[i][j]<<" ";}
cout<<endl;*/
while (i&&j)
		{
			if (a[i]==b[j]) {v[p]=a[i];i--;j--;p++;}
			else
				if (c[i][j-1]>c[i-1][j]) j--;
				else i--;
		}
g<<c[m][n]<<'\n';
for (i=p-1;i>0;i--) g<<v[i]<<" ";
f.close();
g.close();
return 0;
}