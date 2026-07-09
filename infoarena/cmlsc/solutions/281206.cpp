#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024],b[1024],s[1024],c[1024][1024],i,j,n,m,x;
void cmlsc(int i,int j)
{  if (!i||!j) return;
   if (a[i]==b[j]) { x++;
		     s[x]=a[i];
		     cmlsc(i-1,j-1);}
   else if (c[i-1][j]<c[i][j-1]) cmlsc(i,j-1); else
				 cmlsc(i-1,j);}
int main()
	{fin>>n>>m;
	for (i=1;i<=n;i++)          // 0- sus+stanga; 1- sus; 2- stanga
		fin>>a[i];
	for (i=1;i<=m;i++)
		fin>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		  if (a[i]==b[j])
			c[i][j]=c[i-1][j-1]+1;
		   else if (c[i-1][j]>=c[i][j-1])
			 c[i][j]=c[i-1][j];
			else
			 c[i][j]=c[i][j-1];
	fout<<c[n][m]<<'\n';
	cmlsc(n,m);
	for (i=x;i>0;i--)
		fout<<s[i]<<' ';
fout.close();
return 0;}