#include<cstdio>
int lung[1025][1025];
int a[1025];
int b[1025];
int n,m;
void read(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
}
int max(int x,int y){
	if(x>y) return x;
	return y;
}
int lngh(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				lung[i][j]=lung[i-1][j-1]+1;
			else lung[i][j]=max(lung[i-1][j],lung[i][j-1]);
	return lung[n][m];
}
int cmbk(int i,int j){
	while(i>0 && j>0){
		if(a[i]==b[j]){
			cmbk(i-1,j-1);
			printf("%d ",a[i]);
			return 0;
		}
		else if(i-1>0 && lung[i][j]==lung[i-1][j])
			i--;
		else j--;
	}
}
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	printf("%d\n",lngh());
	cmbk(n,m);
	return 0;
}
