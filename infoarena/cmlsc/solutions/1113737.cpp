#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1024],b[1024],sol[1024][1024],n,m;
int maxi(int x,int y)
{
	if(x>y) return x;
	else return y;
}
void solve()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else sol[i][j]=maxi(sol[i-1][j],sol[j-1][i]);
}
void afisare(int x,int y,int k)
{
	if(k>0)
	{
		if(a[x]==b[y])
		{ afisare(x-1,y-1,k-1);
			g<<a[x]<<" ";
		}
		else if(sol[x-1][y]>sol[x][y-1])afisare(x-1,y,k);
				else afisare(y,x-1,k);
	}
}
int main()
{
	int i;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	solve();
	g<<sol[n][m]+1<<'\n';
	afisare(n,m,sol[n][m]+1);
	
	return 0;
}
