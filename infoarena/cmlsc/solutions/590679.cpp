#include<stdio.h>
int a[1030],b[1030],recon[1030],d[1030][1030];
int max(int x,int y){
	if(x>y)return x;return y;
}
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j,max1;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}
	printf("%d\n",d[m][n]);
	max1=d[m][n];
	i=m;j=n;
	recon[0]=max1;
	while(max1){
		if(a[i]==b[j]){
			recon[max1]=a[i];
			i--;
			j--;
			max1--;
		}
		else{
			if(d[i][j-1]>d[i-1][j])j--;else i--;
		}
	}
	for(i=1;i<=recon[0];i++)printf("%d ",recon[i]);
	return 0;
}
