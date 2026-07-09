#include<fstream.h>
#define max(a,b) ((a>b)?(a):(b))
int v0[1100],v1[1100],c[1100][1100],i,j,n,m,li,co,k;
int main()
{
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++)f>>v0[i];
for(i=1;i<=m;i++)f>>v1[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(v0[i]==v1[j])c[i][j]=c[i-1][j-1]+1;
		else if(c[i-1][j]>c[i][j-1])
			c[i][j]=c[i-1][j];
		     else c[i][j]=c[i][j-1];
g<<c[n][m]<<'\n';
k=c[n][m];
li=n;
co=m;
while(k)
	{
	while(c[li-1][co]==k&&c[li][co-1]==k)
		{
		if(c[li-1][co-1]==k){li--;co--;}
		else if(c[li-1][co]==k)li--;
		else co--;
		}
	g<<v0[li]<<" ";
	k--;
	}
f.close();
g.close();
return 0;
}