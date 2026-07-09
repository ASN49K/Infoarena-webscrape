#include <cstdio>

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
int sol[2000],k=1;

int main ()
{
	citire();
	int l=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=l;j<=m;j++)
			if(a[i]==b[j]){
				sol[k++]=a[i];
				l=j;
				break;
			}
	}
	printf("%d\n",k-1);
	for(int i=1;i<k;i++)
		printf("%d ",sol[i]);
}
