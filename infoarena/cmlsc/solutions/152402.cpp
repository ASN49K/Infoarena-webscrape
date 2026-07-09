//cel mai lung subsir comun -> a=(1 7 3 9 8); b=(7 8 9) => cmlsc=(7 8)
#include<cstdio>

long a[1500],b[1500],x[1500][1500],i,n,m,j,y[1500],z,nr;

long max(long x, long y){
	if(x>y)
		return x;
	return y;
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld%ld",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%ld",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%ld",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else
				x[i][j]=max(x[i-1][j],x[i][j-1]);
		}
	printf("%ld\n",x[m][n]);
	i=m;j=n;nr=x[m][n];
	while(i>0 || j>0)
		if(a[i]==b[j]){
			y[nr--]=a[i];
			i--;
			j--;
		}
		else{
			z=max(x[i][j-1],x[i-1][j]);
			if(z==x[i][j-1])
				j--;
			else
				i--;
		}
	for(i=1;i<=x[m][n];i++)
		printf("%ld ",y[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
