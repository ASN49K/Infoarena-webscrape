#include <stdio.h>

int m,n,a[1025],b[1025];
int c[1025][1025],sol[1025],k=1;

int max(int a, int b){
	return a>b?a:b;
}

void formsol(int lin,int col){
	while(lin){
		if(b[lin]==a[col]){
			sol[k++]=b[lin];
			--lin;
			--col;
		}
		else if(c[lin-1][col]<c[lin][col-1])
			--col;
		else
			--lin;
	}
}

int main(){
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(a[j]==b[i])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
		}
   formsol(n,m);
   for(i=k-1;i>=1;i--)
       printf("%d ",sol[i]);
   printf("\n");
   fclose(stdout);
   return 0;
}
