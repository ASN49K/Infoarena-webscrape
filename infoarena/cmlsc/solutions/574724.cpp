#include <fstream>

#define DIM 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(){
	int a[DIM],b[DIM],c[DIM][DIM],s[DIM],m,n,k,i,j;
	fin>>m>>n;
	for (i=1; i<=m; ++i){
		fin>>a[i];
		c[i][0]=0;
	}
	for (j=1; j<=n; ++j){
		fin>>b[j];
		c[0][j]=0;
	}
	for (i=1; i<=m; ++i)
		for (j=1; j<=n; ++j)
			if (a[i] == b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=c[i-1][j] > c[i][j-1] ? c[i-1][j] : c[i][j-1];

	i=m; j=n; k=0;
	fout<<c[i][j]<<"\n";
	while (i && j){
		if (a[i] == b[j]){
			s[++k]=a[i];
			i--;
			j--;
		}
		else
			if (c[i-1][j] < c[i][j-1])
				j--;
			else
				i--;
	}
	for (i=k; i>0; --i)
		fout<<s[i]<<" ";
	fin.close();
	fout.close();
	return 0;
}
