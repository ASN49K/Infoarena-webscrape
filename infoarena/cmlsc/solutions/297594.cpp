#include<fstream.h>
int b[100],l,lcs[100][100],i,j,m,n,x[100],y[100],k,v[100];
int main (){
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for (i=1;i<=n;i++)
	f>>x[i];
for(i=1;i<=m;i++)
	f>>y[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
	if(x[i]==y[j])
		lcs[i][j]=1+lcs[i-1][j-1];
else
	if(lcs[i-1][j]>lcs[i][j-1])
		lcs[i][j]=lcs[i-1][j];
	else
		lcs[i][j]=lcs[i][j-1];

i=n;
j=m;
while (lcs[i][j]!=0)
if (x[i]==y[j])
	{k++;
	v[k]=x[i];
	lcs[i][j]=lcs[i-1][j-1];
	i--;
	j--;}
else
	if(lcs[i][j]==lcs[i-1][j])
		i--;
	else
		if (lcs[i][j]==lcs[i][j-1])
			j--;
l=0;
g<<k<<'\n';
for(i=k;i>=1;i--)
	{l++;
	b[l]=v[i]; }
for(i=1;i<=l;i++)
	g<<b[i]<<" ";
f.close();
g.close();}