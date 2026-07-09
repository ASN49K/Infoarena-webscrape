#include<fstream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int main()
{
	int a[100][100], n, m, i, j, max = 0, x, y;
	fin>>n>>m;
	for(i=0;i<=n+1;i++)
	for(j=0;j<=m+1;j++)
		a[i][j]=1;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		fin>>a[i][j];
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		{y=a[i][j+1]+a[i][j-1]+a[i+1][j]+a[i-1][j];
		if(y>max)
		{
			max=y;
			x=a[i][j];
		}
		}
		fout<<x<<" "<<max<<" ";
		fin.close();
		fout.close();
}