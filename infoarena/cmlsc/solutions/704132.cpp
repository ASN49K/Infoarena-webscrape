#include<fstream>
using namespace std;
int a[1030],b[1030],i,j,n,m,c[1030][1030],sol[1030],k;
int main()
{ifstream f("cmlsc.in");
ofstream h("cmlsc.out");	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
	if(a[i]==b[j])
		{c[i][j]=c[i-1][j-1]+1;
	k++;
	sol[k]=a[i];}
	
	else
		if(c[i][j-1]>c[i-1][j])
		c[i][j]=c[i][j-1];
	else
		c[i][j]=c[i-1][j];
	
	h<<c[n][m];
	h<<"\n";
	for(i=1;i<=k;i++)
	h<<sol[i]<<" ";	
	
	return 0;}