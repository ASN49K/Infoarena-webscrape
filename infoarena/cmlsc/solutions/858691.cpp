#include <cstdio>

#define MAX(a , b) (( a > b )?a : b)

using namespace std;

int n,m,a[2000],b[2000];

void citire ()
{
	freopen("cmlsc.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
}
int sol[2000],k=1,mat[2000][2000];

int main ()
{
	citire();
	int l=1;
	for(int i=1;i<=n;i++)
		for(int j=l;j<=m;j++){
			if(a[i]==b[j])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j] = MAX(mat[i-1][j],mat[i][j-1]);
		}
	for(int i=n,j=m;i;)
	{
		if(a[i]==b[j]){
			sol[k++]=a[i];
			i--;
			j--;
		}
		else{
			if(mat[i-1][j]<mat[i][j-1])
				j--;
			else
				i--;
		}
	}
	freopen("cmlsc.out","w",stdout);
	/*for(int i=1;i<=m;i++){
		for(int j=l;j<=n;j++)
			printf("%2d ",mat[j][i]);
		printf("\n");
	}*/
	printf("%d\n",k-1);
	for(int i=k-1;i>0;i--)
		printf("%d ",sol[i]);
}
