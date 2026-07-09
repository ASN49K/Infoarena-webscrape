#include <cstdio>

using namespace std;

int n,m,a[1026],b[1026],best[1026][1026],h=0,v[1026],max=0;

void citire()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
}

void afisare()
{
	/*for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d ",b[i]);
	printf("\n");
	*/
	printf("%d\n",h);
	for(int i=h;i>=1;i--)
		printf("%d ",v[i]);
	printf("\n");
}

int main()
{
	freopen("cmlsc.in","rt",stdin);
	freopen("cmlsc.out","wt",stdout);
	citire();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				best[i][j]=best[i-1][j-1]+1;
			else if(best[i-1][j]>best[i][j-1])
				best[i][j]=best[i-1][j];
			else best[i][j]=best[i][j-1];
	int ii=n,jj=m;
	while(ii!=0 && jj!=0)
		if(a[ii]==b[jj])
		{
			h++;
			v[h]=a[ii];
			ii--;
			jj--;
		}
		else if(best[ii-1][jj]<best[ii][jj-1])
			jj--;
		else ii--;
	afisare();
	return 0;
}

