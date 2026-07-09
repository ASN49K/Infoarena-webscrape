#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],i,j,n,m,x[1025],y[1025];
void rec(int n,int m){
	if(n>=1&&m>=1){
		if(y[n]==x[m]){
			rec(n-1,m-1);
			g<<y[n]<<' ';
		}
		else if(a[n-1][m]>=a[n][m-1])
			    rec(n-1,m);
			 else rec(n,m-1);
	}
}
int main(){
f>>m>>n;
for(i=1;i<=m;i++)
	f>>x[i];
for(i=1;i<=n;i++)
	f>>y[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		if(y[i]==x[j])
			a[i][j]=a[i-1][j-1]+1;
	 else if(a[i-1][j]>=a[i][j-1])
		          a[i][j]=a[i-1][j];
		    else a[i][j]=a[i][j-1];
	}
g<<a[n][m]<<'\n';
rec(n,m);
return 0;
}