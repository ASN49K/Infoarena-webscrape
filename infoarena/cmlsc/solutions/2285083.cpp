#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025], b[1025], c[1025][1025], n, m, i, j, k, sol[1025];

int main() {
	cin>>n>>m;
	for(i=1; i<=n; i++)
		cin>>a[i];
	for(i=1; i<=m; i++)
		cin>>b[i];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i][j-1], c[i-1][j]);
	cout<<c[n][m]<<'\n';
	i=n, j=m;
	while(c[i][j])
		if(a[i]==b[j])
			sol[++k]=a[i], i--, j--;
		else
			if(c[i][j-1]>c[i-1][j])
				j--;
			else
				i--;
	while(k)
		cout<<sol[k--]<<' ';
	return 0;
}
