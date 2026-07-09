#include<fstream>
using namespace std;
int a[1030],b[1030],mat[1030][1030],sir[1030],i,j,n,m,r;
int main(){
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for (i=1;i<=n;i++) 
		f>>a[i];
	for (j=1;j<=m;j++)
		f>>b[j];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j]) 
				mat[i][j]=mat[i-1][j-1]+1;
			else
				if (mat[i-1][j]>mat[i][j-1])
					mat[i][j]=mat[i-1][j];
				else
					mat[i][j]=mat[i][j-1];
	g<<mat[n][m]<<"\n";
	i=n;j=m;
	while (mat[i][j]){
		while (mat[i][j]==mat[i-1][j])
			i--;
		while (mat[i][j]==mat[i][j-1])
			j--;
		r++;
		sir[r]=b[j];
		i--;
		j--;
	}
	for (i=r;i>=1;i--)
		g<<sir[i]<<" ";
	return 0;
}