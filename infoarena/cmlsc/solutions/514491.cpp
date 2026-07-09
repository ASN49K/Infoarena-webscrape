#include <cstdio>
int lcs[1024][1024];
int v1[1024];
int v2[1024];
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int m,n,mx=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",v1+i);
	for(int i=1;i<=n;i++)
		scanf("%d",v2+i);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(v1[i]!=v2[j])
				lcs[i][j]=0;
			else{
				lcs[i][j]=lcs[i-1][j-1]+1;
				if(lcs[i][j]>mx)
					mx=lcs[i][j];
			}
	printf("%d\n",mx);
	return 0;
}

