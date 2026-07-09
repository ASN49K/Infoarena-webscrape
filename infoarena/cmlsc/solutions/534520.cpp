#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N=2000;
int a[1000][1000],v[N],x[N],n,m;
int sol[11*N];
int k=0;
void read()
{
	in>>n>>m;
	for(int i=1;i<=n;i++)
		in>>v[i];
	for(int j=1;j<=m;j++)
		in>>x[j];
}
inline int max(int q,int w)
{
	return q>w ? q : w;
}
void solve()
{
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(v[i]==x[j])
			{
				a[i][j]=1+a[i-1][j-1];
				sol[++k]=x[j];
			}
			else
				a[i][j]=max(a[i-1][j],a[i][j-1]);
	out<<a[n][m]<<'\n';
}
void afis()
{
		for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			out<<a[i][j]<<" ";
		out<<'\n';
		}
}
int main()
{
	read();
	solve();
	for(int i=1;i<=k;i++)
		out<<sol[i]<<" ";
	return 0;
}
