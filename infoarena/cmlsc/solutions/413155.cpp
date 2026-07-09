#include <fstream>
using namespace std;
int v[2048][2048],a[2048],b[2048];

int main()
{
	int n,m,i,j;
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	in>>n>>m;
	for (i=1;i<=n;i++)
		in>>a[i];
	for (i=1;i<=m;i++)
		in>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else 
				v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
	out<<v[n][m];
	return 0;
}
