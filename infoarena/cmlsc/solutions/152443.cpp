//cel mai lung subsir comun -> a=(1 7 3 9 8); b=(7 8 9) => cmlsc=(7 8)
#include<cstdio>

int a[1030],b[1030],x[1030][1030],i,n,m,j,y[1030],z,nr;

int max(int x, int y){
	if(x>y)
		return x;
	return y;
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else
				x[i][j]=max(x[i-1][j],x[i][j-1]);
		}
	printf("%d\n",x[m][n]);
	for(i=m,j=n,nr=0;i;)
		if(a[i]==b[j]){
			y[nr++]=a[i];
			i--;
			j--;
		}
		else{
		//	z=max(x[i][j-1],x[i-1][j]);
			if(x[i][j-1]>x[i-1][j])
				j--;
			else
				i--;
		}
//	printf("%ld\n",nr-1);
	for(i=nr-1;i>=0;i--)
		printf("%d ",y[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
