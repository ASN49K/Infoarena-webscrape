#include <fstream.h>
#define N 1050
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[N],b[N],q[N][N],n,m,x,y;
void citire()
{
int i;
fin>>n>>m;
for(i=1;i<=n;i++)
	fin>>a[i];
for(i=1;i<=m;i++)
	fin>>b[i];
}
int max(int a,int b)
{
if(a>b) return a;
return b;
}
void PD()
{
int i,j;
for(i=0;i<=n;i++)
	q[i][0]=0;
for(i=0;i<=m;i++)
	q[0][i]=0;
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		if(a[i]==b[j]) q[i][j]=q[i-1][j-1]+1;
		else q[i][j]=max(q[i-1][j],q[i][j-1]);
}
int write(int z,int t)
{
if(z==0||t==0) return 0;
if(a[z]==b[t])
	{
	write (z-1,t-1);
	fout<<a[z]<<' ';
	}
else
	if(q[z-1][t]>q[z][t-1]) write (z-1,t);
	else write (z,t-1);
	
return 0;
}
int main()
{
citire();
PD();
fout<<q[n][m]<<'\n';
write(n,m);
return 0;
}