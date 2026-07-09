#include <stdio.h>
#define val 1026
int i  , j , n , m , V[val][val], A[val],B[val],Z[val] , ln , k;
int max(int x , int y){
	if(x>y)
		return x;
	return y;
}
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&B[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(A[i]==B[j])
				V[i][j]=1+V[i-1][j-1];
			else{
				V[i][j]=max(V[i-1][j],V[i][j-1]);
			}
		}
	}
	printf("%d\n",V[n][m]);
	ln=V[n][m];i=n;j=m;
	while(ln){
		if(A[i]==B[j]){
			Z[++k]=A[i];i--;j--;ln--;
		}
		else{
			if(V[i-1][j]>V[i][j-1])
				i--;
			else
				j--;
		}
	}
	for(i=k;i>=1;i--)
		printf("%d ",Z[i]);
	return 0;
}