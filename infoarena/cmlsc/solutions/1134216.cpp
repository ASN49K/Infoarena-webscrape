#include <cstdio>
using namespace std;
int a[1030],b[1030],n,m,mat[1030][1030],i,j,stiv[1030],ind;
int max2(int a, int b){if(a>b){return a;}return b;}
int max3(int a, int b, int c){return max2(max2(a,b),c);}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%ld",&a[i]);
					 }
	for(i=1;i<=m;i++){
		scanf("%ld",&b[i]);
		for(j=1;j<=n;j++){
			if(a[j]==b[i]){
				mat[i][j]=max3(mat[i-1][j],mat[i][j-1],mat[i-1][j-1]+1);
						  }
			else{mat[i][j]=max2(mat[i-1][j],mat[i][j-1]);}
						 }
					 }
	printf("%ld\n",mat[m][n]);
	i=m;j=n;ind=0;
	while((i)&&(j)){
		if(a[j]==b[i]){stiv[++ind]=a[j];i--;j--;}
		else{
			if(mat[i][j]==mat[i-1][j]){i--;}
			if(mat[i][j]==mat[i][j-1]){j--;}
			}
				   }
	while(ind){printf("%d ",stiv[ind--]);}
return 0;
}