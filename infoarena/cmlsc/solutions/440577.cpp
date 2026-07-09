#include<fstream>
using namespace std;
#define nmax 1025
int lsc[nmax][nmax],n,m,a[nmax],b[nmax],sc[nmax];
int maxim(int p,int q)
{
	if(p>q)
		return p;
	return q;
}
void citire()
{
	int i;
	freopen("cmlsc.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
}
void bottom_up()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				lsc[i][j]=lsc[i-1][j-1]+1;
			else
				lsc[i][j]=maxim(lsc[i-1][j],lsc[i][j-1]);
}
void afisare()
{
	freopen("cmlsc.out","w",stdout);
	printf("%d\n",lsc[n][m]);
	int i,j,pas,poz=0;
	pas=lsc[n][m];i=n;j=m;
	while(pas)
	{
		while(lsc[i][j]==pas) i--;i++;
		while(lsc[i][j]==pas) j--;
		poz++;sc[poz]=a[i];
		i--;pas--;
	}
	for(i=poz;i>0;i--)
		printf("%d ",sc[i]);
}
int main()
{
	citire();
	bottom_up();
	afisare();
}
