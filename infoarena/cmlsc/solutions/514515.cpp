#include <cstdio>
#undef DBG
#define max(x,y) (((x)>(y))?(x):(y))
int lcs[1024][1024];
int v1[1024];
int v2[1024];
void bt(int i,int j){
	if(!(i&&j))
		return;
	if(v1[i]==v2[j]){
		bt(i-1,j-1);
		printf("%d ",v1[i]);
		return;
	}
	if(lcs[i][j-1]>lcs[i-1][j])
		bt(i,j-1);
	else
		bt(i-1,j);
}
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
		for(int j=1;j<=n;j++){
			if(v1[i]==v2[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
			if(lcs[i][j]>mx)
				mx=lcs[i][j];
		}
	#ifdef DBG
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",lcs[i][j]);
		printf("\n");
	#endif
	printf("%d\n",mx);
	bt(m,n);
	return 0;
}
