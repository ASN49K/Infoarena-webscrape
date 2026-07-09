#include<fstream>
using namespace std;
int x[1001],y[1001],n,m,sol[1001][1001];
int rez(void)
{
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(y[i]==x[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				sol[i][j]=(sol[i-1][j]>sol[i][j-1])?(sol[i-1][j]):(sol[i][j-1]);
	return sol[m][n];
}
int main(void)
{
	int i;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=m;i++)
		f>>y[i];
	g<<rez()<<"\n";
	for(i=1;i<=m;i++)
		if(sol[i-1][n]!=sol[i][n])
			g<<y[i]<<" ";
	
}