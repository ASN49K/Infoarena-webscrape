#include<fstream.h>
#define NM 1025

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int x[1025],y[1025],m,n,a[NM][NM]={{0}},v[NM],nr;

int main(){
int i,j;
in>>n>>m;
for(i=1;i<=n;++i)
	in>>x[i];
for(j=1;j<=m;++j)
	in>>y[j];

for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
		if(x[i]==y[j])
			a[i][j]=a[i-1][j-1]+1;
		else
			if(a[i][j-1]>=a[i-1][j])
				a[i][j]=a[i][j-1];
			else
				a[i][j]=a[i-1][j];
out<<a[n][m]<<"\n";
i=n,j=m;
nr=a[n][m];
while(i&&j){
	if(x[i]==y[j]){
		//out<<x[i]<<" ";
		v[nr--]=x[i];
		i--;j--;
		continue;
		}
	if(i&&j&&a[i][j-1]>=a[i-1][j]){
		j--;
		}
	else
	    i--;
	}
for(i=1;i<=a[n][m];++i)
	out<<v[i]<<" ";
return 0;
}
