#include <fstream>
using namespace std;
int v[1025],w[1025],b[1025][1025],x[1025][1025],bst,bstcp,sol[1025];
int main() {
	int n,m,i,j;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for (i=1; i<=n; i++)
		f>>v[i];
	for (i=1; i<=m; i++)
		f>>w[i];
	
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++) {
			if (v[i]==w[j]) {
				b[i][j]=b[i-1][j-1]+1;
				x[i][j]=1;
			}
			else if (v[i]!=w[j]) {
				if (b[i-1][j]>b[i][j-1]) {
					b[i][j]=b[i-1][j];
					x[i][j]=2;
				}
				else if (b[i][j-1]>b[i-1][j]) {
					b[i][j]=b[i][j-1];
					x[i][j]=3;
				}
				else if (b[i-1][j]==b[i][j-1]) {
					if (v[i-1]>=w[j-1]) {
						b[i][j]=b[i-1][j];
						x[i][j]=2;
					}
					else {
						b[i][j]=b[i][j-1];
						x[i][j]=3;
					}
				}
			}
		}
	bst=b[n][m];
	bstcp=bst;
	i=n; j=m;
	while (bstcp) {
		if (x[i][j]==1) {
			sol[bstcp]=v[i];
			i--; j--;
			bstcp--;
		}
		else if (x[i][j]==2)
			i--;
		else
			j--;
	}
	g<<bst<<'\n';
	for (i=1; i<=bst; i++)
		g<<sol[i]<<' ';
	g<<'\n';
	g.close();
	return 0;
}

			