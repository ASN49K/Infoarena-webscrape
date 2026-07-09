#include<stdio.h>
using namespace std;
int a[1025],b[1025], matrice[1025][1025];
int n,m;

void afis(int i,int j)
{
	if(i>0&&j>0)
	if (a[i]==b[j])
	{afis(i-1,j-1);
	printf("%d ",a[i]);
	}
	else
		if (matrice[i-1][j]>matrice[i][j-1])
			afis(i-1,j);
			else afis(i,j-1);

}
int max(int a,int b)
{
	if (a>b) return a;
	return  b;
}
int main()
{
	int i,j;
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++)
	 scanf("%d ",&a[i]);
	for(j=1;j<=m;j++)
	  scanf("%d ",&b[j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
			   	matrice[i][j]=matrice[i-1][j-1]+1;
				else
					matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
				
			printf("%d\n",matrice[n][m]);
			
			afis(n,m);		 
			return 0;
	
	

}