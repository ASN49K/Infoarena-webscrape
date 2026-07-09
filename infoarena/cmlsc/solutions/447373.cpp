#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1030][1030], x[1030], y[1030], s[1030], n, m, i, j, k;
int main(){
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=m;i++)
		f>>y[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(x[i]==y[j]) 
				a[i][j]=a[i-1][j-1]+1;
			else
				if(a[i][j-1]<a[i-1][j])
					a[i][j]=a[i-1][j];
				else 
					a[i][j]=a[i][j-1];
	g<<a[n][m]<<'\n';
	i=n;
	j=m;
	while(i!=0&&j!=0)
		if(x[i]==y[j]){
			s[++k]=y[j];
			i--;
			j--;
		}
		else 
			if(a[i][j-1]>a[i-1][j])
				j--;
			else i--;
	for(i=k;i>=1;i--)
		g<<s[i]<<" ";
	f.close();
	g.close();
	return 0;
}
			
		