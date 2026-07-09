#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a[1100],b[1100],i,j,mat[1100][1100],v[1100],k=1,poz;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	if(a[1]==b[1]){
		mat[1][1]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j]){
				mat[i][j]=mat[i-1][j-1]+1;
			}else{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
		}
	}
	printf("%d\n",mat[n][m]);
	
	i=n; 
	j=m;
	while(i>0&&j>0){
			
			if(a[i]==b[j]){
				v[k]=a[i];
				k++;
			}else{
				if (mat[i-1][j]<mat[i][j-1])
					--j;
				else           
					--i;
			}
		
	}
			
	for(i=mat[n][m];i>=1;i--){
		printf("%d ",v[i]);
	}
	return 0;
}