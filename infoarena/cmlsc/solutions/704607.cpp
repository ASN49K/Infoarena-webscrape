#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream hout("cmlsc.out");
struct punct{int x,y,c;};
punct p[1030][1030];
int a[1030],b[1030],i,j,n,m,c[1030][1030],k;
	
void afis(int xx,int yy)
{int aa,bb;
aa=xx;
bb=yy;
	
xx=p[xx][yy].x;
yy=p[xx][yy].y;
if(p[xx][yy].x!=0&&p[xx][yy].y!=0)
afis(xx,yy);
	
	if(p[aa][bb].c==1)
	hout<<a[aa]<<" ";

	
}
int main()
{

	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>a[i];
	for(i=1;i<=m;i++)
		fin>>b[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
	if(a[i]==b[j])
	{c[i][j]=c[i-1][j-1]+1;
	p[i][j].c=1;
	p[i][j].x=i-1;
	p[i][j].y=i-1;}
		else
		if(c[i][j-1]>c[i-1][j])
	{	c[i][j]=c[i][j-1];
	
	p[i][j].x=i;
	p[i][j].y=j-1;
	}	
		
	else
	{	p[i][j].x=i-1;
	p[i][j].y=j;
		
		c[i][j]=c[i-1][j];}
	
	
	
	
	hout<<c[n][m];
	hout<<"\n";
	afis(n,m);
	
	return 0;}