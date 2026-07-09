#include<fstream>
using namespace std;
int a[1025],b[1025],n,m,i,j,c[1025][1025];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void printsol(int i,int j)
{
	if(c[i][j]==0) return;
	else
		if(a[i]==b[j]){
			printsol(i-1,j-1);
			g<<a[i]<<" ";}
		else
			if(c[i][j]==c[i-1][j])
				printsol(i-1,j);
			else
				printsol(i,j-1);

}
int main( void )
{
	f>>n>>m;
	for(i=1;i<=n;i++) f>>a[i];
	for(j=1;j<=m;j++) f>>b[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
			else if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
			else c[i][j]=c[i][j-1];
	g<<c[n][m]<<endl;
	printsol(n,m);
	g<<endl;
	g.close();
}
