#include <fstream>
#include <vector>

using namespace std;
const int MAXN=1e3+50;
int n,m;
int a[MAXN],b[MAXN],d[MAXN][MAXN];
vector<int>v;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			d[i][j]=max(d[i-1][j],d[i][j-1]);
			if (a[i]==b[j]) d[i][j]++;
		}
	}
	for (int i=n,j=m;j>=1 && i>=1;)
	{
		if (a[i]==b[j])
		{
			v.push_back(a[i]);
			i--;
			j--;
		}
		else if (d[i-1][j]>d[i][j-1]) i--;
		else j--;
	}
	cout<<d[n][m]<<"\n";
	for (int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
}
