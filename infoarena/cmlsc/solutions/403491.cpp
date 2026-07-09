#include<cstdio>
#include<vector>
#define lg_max 1024
using namespace std;
int lcs[lg_max][lg_max],a[lg_max],b[lg_max],sir[lg_max];
inline int Max(int i,int j) { if(i>j) return i; else return j; }
int main()
{
	int n,m,j,i,lg;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	//citire date 
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;i++)		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)		scanf("%d",&b[i]);
	
	//matrice ... cu numarul de siruri
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])		lcs[i][j]=lcs[i-1][j-1]+1;
			else 				lcs[i][j]=Max(lcs[i-1][j],lcs[i][j-1]);
	
	for(i=n,j=m,lg=0;i!=0;)
	{
		if(a[i]==b[j])
		{
			sir[++lg]=a[i];
			i--;j--;
		}
		else if(lcs[i-1][j]<lcs[i][j-1]) j--;
		else 	i--;
			
	}
	printf("%d\n",lg);
	for(i=lg;i>=1;i--)
		printf("%d ",sir[i]);
	//afisare matrice subsiruri comune
	//for(i=1;i<=n;i++){	for(j=1;j<=m;j++)printf("%d ",lcs[i][j]);printf("\n");}
	return 0;
}

