#include <fstream>

using namespace std;

int n, m, i, j,k;

int d[1030][1030], a[1030],b[1030],sol[1030];

int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(j=1;j<=n;j++)
		f>>b[j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	g<<d[m][n]<<"\n";
	i=m;j=n;
	while(i>=1 && j>=1) {
			if(a[i]==b[j]) {
				sol[++k]=a[i];
				i--;j--;
			}
			else
				if(d[i-1][j]>d[i][j-1])
					i--;
				else
					j--;
	}
	for(i=k;i>=1;i--)
		g<<sol[i]<<" ";
	return 0;
}
