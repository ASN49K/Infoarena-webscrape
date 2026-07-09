#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1026],b[1026],mat[1026][1026]; 
int maxim(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
void afis(int i, int j)
{
	if(i>0 && j>0)
		if(a[i]==b[j])
		{
			afis(i-1,j-1);
			g<<a[i]<<" ";
		}
		else
		{
			if(max(mat[i][j-1],mat[i-1][j])==mat[i][j-1])
				afis(i,j-1);
			else
				afis(i-1,j);
		}
}
int main()
{
	f>>n>>m;
	for(int i=1;i<=n;i++)
		f>>a[i];
	for(int i=1;i<=m;i++)
		f>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
	g<<mat[n][m]<<'\n';
	afis(n,m);
	return 0;
}
