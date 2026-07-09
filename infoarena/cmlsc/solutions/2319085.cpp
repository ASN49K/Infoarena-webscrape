#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,k,a[1030],b[1030],c[1030][1030],sol[1030];

int main() {
	fin>>n>>m;
	for (i=1;i<=n;i++)
		fin>>a[i];
	for (i=1;i<=m;i++)
		fin>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	fout<<c[n][m]<<'\n';
	while (c[n][m])
		if (a[n]==b[m]){
			n--;
			m--;
			sol[++k]=a[n+1];
		}
		else
			if (c[n-1][m]>c[n][m-1])
				n--;
			else
				m--;
	for (i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    fin.close();
    fout.close();
	return 0;
}
