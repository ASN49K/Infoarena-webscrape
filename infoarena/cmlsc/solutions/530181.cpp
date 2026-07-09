#include<fstream>
using namespace std;
int n,m,a[1025],b[1025],sol[1025][1025],d[1025];

void cmlsc()
{int i,j,l=0,c=0,k;
   ofstream g("cmlsc.out");
	for(i=n;i>=1;i--)
	  for(j=m;j>=1;j--)
		if(a[i]==b[j])sol[i][j]=sol[i+1][j+1]+1;
	      else
		if(sol[i][j+1]>=sol[i+1][j])sol[i][j]=sol[i][j+1];
		  else
		sol[i][j]=sol[i+1][j];
	 g<<sol[1][1]<<"\n";

  for(k=sol[1][1];k>=1;k--)
	{
	 for(i=l+1;i<=n;i++)
	  for(j=c+1;j<=m;j++)
		if(sol[i][j]==k && a[i]==b[j])
		{
			d[k]=a[i];
			l=i;c=j;
			break;
		}

	 }
	for(i=sol[1][1];i>=1;i--)
		g<<d[i]<<" ";
	g.close();
}

int main()
{int i,j;
	ifstream f("cmlsc.in");
	f>>n>>m;
	for(i=1;i<=n;i++) f>>a[i];
	for(i=1;i<=m;i++) f>>b[i];
	cmlsc();

	f.close();
return 0;}
