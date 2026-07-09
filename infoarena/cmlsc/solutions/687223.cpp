#include<cstdio>
int b,max,n,i,j,k,x,a[1025],rez[1025];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=k;i++) {
		scanf("%d",&x);
		for (j=1;j<=n;j++) if (x==a[j]) {
			b=rez[j-1]+1;
			while (j<=n) {
				if (rez[j]==b) break;
				rez[j]=b;j++;
			}
		}
	}
	printf("%d\n",rez[n]);
	max=1;
	for (i=1;i<=n;i++) if (rez[i]==max) max++,printf("%d ",a[i]);
	return 0;
}
	