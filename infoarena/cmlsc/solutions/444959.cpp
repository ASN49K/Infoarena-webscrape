#include <iostream>
int i,j,c[1024][1024],v[1024];
void krs(int n, int n2) {
	for (i=(n2+1);i>0;i--)
		for (j=(n+1);j>0;j--) 
			if (i==n2+1) c[i][j]=0;
			else if (j==n+1) c[i][j]=0;
			else if (c[0][j]==c[i][0]) c[i][j]=c[i+1][j+1]+1;
			else c[i][j]=(c[i+1][j]>c[i][j+1]) ? c[i+1][j] : c[i][j+1];
	
}
int main (void) {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,n2,db=0;
	scanf("%d %d",&n,&n2);
	for (i=1;i<=n;i++) 
		scanf("%d",&c[0][i]);
	for (i=1;i<=n2;i++)
		scanf("%d",&c[i][0]);
	krs(n,n2);
	i=1;j=1;
	while((i<=n2) && (j<=n)) {
		if (c[0][j]==c[i][0]) {
			db++;
			v[db]=c[0][j];
			i++;j++;
		}else if (c[i][j]==c[i][j+1]) j++;
		else i++;
	}
	printf("%d\n",db);
	for (i=1;i<=db;i++)
		printf("%d ",v[i]);		
}
