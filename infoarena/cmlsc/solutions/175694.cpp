#include<fstream.h>

void main()
{int x[1001],y[1001],z[1001],a[1001][1001]={0},n,m,i,j,k;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n;
for(i=1;i<=n;i++) f>>x[i];
f>>m;
for(i=1;i<=m;i++) f>>y[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
   	if(x[i]==y[j])a[i][j]=a[i-1][j-1]+1;
      else
      if(a[i][j-1]>a[i-1][j])a[i][j]=a[i][j-1];
      	else a[i][j]=a[i-1][j];
g<<a[n][m]<<endl;
i=n;j=m;k=1;
while(i>0&&j>0)
	if(x[i]==y[j]){z[k++]=x[i];i--;j--;}
   else
   if(a[i][j-1]>a[i-1][j])j--;
   		else i--;
for(i=k-1;i>0;i--)g<<z[i]<<" ";
}
