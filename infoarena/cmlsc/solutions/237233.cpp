#include <iostream>

using namespace std;

int main ( int argc, char *argv[] )
{
	int mat[1024][1024];
	int v1[1024],v2[1024],s[1024];
	int m,n,i,j;
	
	freopen("cmlsc.out","wt",stdout);
	freopen("cmlsc.in","rt",stdin);
	scanf("%d%d",&m,&n);
	j=m>n?m:n;
	for(i=0;i<j;i++)
		mat[0][i]=mat[i][0]=0;
	for(i=0;i<m;i++)
		scanf("%d",&v1[i]);
	for(i=0;i<n;i++)
		scanf("%d",&v2[i]);
	
	for(i=1;i<m;i++)
		for(j=1;j<n;j++){
			if(v1[i-1]==v2[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=mat[i][j-1]>mat[i-1][j]?mat[i][j-1]:mat[i-1][j];
		}
	int k=mat[m-1][n-1];
	printf("%d\n",k);
	i=m-1;
	j=n-1;
	while(k){
		if(v1[i]==v2[j]){
			k--;
			s[k]=v1[i];
			i--;j--;
		}
		else 
			mat[i-1][j]>mat[i][j-1]?i--:j--;
	}
	for(i=0;i<mat[m-1][n-1];i++)
		printf("%d ",s[i]);
	return 0;
}
