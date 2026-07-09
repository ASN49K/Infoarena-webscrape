#include<fstream>
using namespace std;
int x[1025],y[1025],a[1025][1025],n,m;
ifstream fcin("cmlsc.in");
ofstream gcout("cmlsc.out");
void afis(int i,int j)
{
if(i!=0 and j!=0)
	if(x[i]==y[j]){afis(i-1,j-1);gcout<<x[i]<<" ";}
	else if(a[i][j]==a[i][j-1])afis(i,j-1);
	else afis(i-1,j);
}
int main ()
{

int i,j;
fcin>>n>>m;
for(i=1;i<=n;i++)
	fcin>>x[i];
for(j=1;j<=m;j++)
	fcin>>y[j];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(x[i]==y[j])a[i][j]=a[i-1][j-1]+1;
	else a[i][j]=(a[i-1][j]>a[i][j-1])?a[i-1][j]:a[i][j-1];
gcout<<a[n][m]<<"\n";
afis(n,m);
return 0;
}