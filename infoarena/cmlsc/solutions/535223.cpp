#include<stdio.h>
#include<string.h>
int c[1025][1025],a[1025],b[1025],d[1025],t,i,j,n,m;
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for (i=1; i<=m; i++){
		scanf("%d",&b[i]);
	}
	memset(c,sizeof(c),0);
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else if (a[i]!=b[j]){
					if (c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
					else c[i][j]=c[i][j-1];
			}
		}
	}
	i=n;
	j=m;
	t=0;
	while (i>0 && j>0){
		if (a[i]==b[j]){
			t++;
			d[t]=a[i];
			i--;
			j--;
		}
		else if (a[i]!=b[j]){
			if (c[i-1][j]>c[i][j-1]){
				i--;
			}
				else j--;
		}
	}
	printf("%d\n",t);
	for (i=t; i>=1; i--) printf("%d ",d[i]);
	return(0);
}
