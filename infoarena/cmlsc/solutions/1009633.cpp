#include<fstream>
using namespace std;
int x[1025],y[1025],n,m,sol[1025][1025];
ofstream g("cmlsc.out");
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
int afis(int i,int j)
{
	if(sol[i][j]==0)
		return 0;
	while(sol[i-1][j-1]==sol[i][j])
	{
		i--;j--;
	}
	while(sol[i-1][j]==sol[i][j])
		i--;
	while(sol[i][j-1]==sol[i][j])
		j--;
	
	afis(i-1,j-1);
	g<<y[i]<<" ";
	
}
int main(void)
{
	int i;
	ifstream f("cmlsc.in");
	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>x[i];
	for(i=1;i<=m;i++)
		f>>y[i];
	g<<rez()<<"\n";
	afis(m,n);
	
}