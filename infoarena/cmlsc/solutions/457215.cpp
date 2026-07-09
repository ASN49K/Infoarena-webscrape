#include <fstream.h>

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

#define MAXX 1026

int x[MAXX],y[MAXX],a[MAXX][MAXX],n,i,j,m,sol[MAXX],k;

int main(){
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=m;i++)
		f>>y[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				a[i][j]=1+a[i-1][j-1];
			else if(a[i][j-1]>a[i-1][j])
					a[i][j]=a[i][j-1];
			else a[i][j]=a[i-1][j];
	i=n;
	j=m;
	while(i>0&&j>0)
		if(x[i]==y[j]){
			sol[++k]=x[i];
			i--;
			j--;
		}
		else if(a[i][j-1]>a[i-1][j])
				j--;
		else i--;
		
	g<<a[n][m]<<"\n";
	for(i=k;i>0;i--)
		g<<sol[i]<<" ";
	
	return 0;
}