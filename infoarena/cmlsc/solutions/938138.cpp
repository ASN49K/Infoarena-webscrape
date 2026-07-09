#include<fstream>
#include<iostream>
#define max(a,b) a>b?a:b
using namespace std;

int main()
{

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,sol[1025],i,j,k=0;
f>>n>>m;
int a[n+1],b[m+1],x[n+1][m+1];

for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];

for(i=0;i<=n;i++) x[i][0]=0;
for(i=0;i<=m;i++) x[0][i]=0;

for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j])
			x[i][j]=x[i-1][j-1]+1; // daca gasit => sir din urma+1
		else
			x[i][j]=max(x[i-1][j],x[i][j-1]);

i=n;j=m;

while(i&&j){
	if(a[i]==b[j])
	{
	sol[++k]=a[i];
	i--;j--;
	}
	else
	if(x[i][j-1]>x[i-1][j])
		j--;
	else
		i--;
}


g<<x[n][m]<<'\n';
for(;k;k--)g<<sol[k]<<" ";

}
