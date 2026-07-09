#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N=2000;
int a[1025][1025],v[N],x[N],n,m;
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
void subsir(int i,int j)
{
	if(!i || !j)
		return;
	if(v[i]==x[j])
	{
		subsir(i-1,j-1);
		out<<v[i]<<" ";
	}
	else
		if(a[i-1][j]>a[i][j-1])
			subsir(i-1,j);
		else
			subsir(i,j-1);
}
int main()
{
	read();
	solve();
	subsir(n,m);
	return 0;
}
