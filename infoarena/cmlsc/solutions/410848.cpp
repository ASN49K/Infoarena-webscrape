#include <fstream.h>
#define max(a,b) ((a>b)?a:b)
int m,n,i,j,a[1024][1024],x[1024],y[1024],sir[1024],k;
int main(){
	ifstream fin("cmlsc.in");
	fin>>m>>n;
	for (i=1;i<=m;i++) fin>>x[i];
	for (i=1;i<=n;i++) fin>>y[i];
	fin.close();
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
	         	if (x[i]==y[j])
					a[i][j]=1+a[i-1][j-1];
				else
					a[i][j]=max(a[i-1][j],a[i][j-1]);
	for (i=m,j=n;i;)
		if (x[i]==y[j])
		{ k++; sir[k]=x[i]; i--; j--; }
		else
			if (a[i-1][j]<a[i][j-1]) 
				 j--;
			else
				i--;
	ofstream fout("cmlsc.out");
	fout<<k<<'\n';
	for (i=k;i>=1;i--)
		fout<<sir[i]<<" ";
	fout<<'\n';
	fout.close();
	return 0;
}
