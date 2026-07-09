#include<stdio.h>

int mat[1025][1025], u[1025], v[1025];

int main(){
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int n, m, i, j, l;
	
	scanf("%d %d ", &n, &m);
	
	for(i=1; i<=n+m; i++){
		if(i<=n)
			scanf("%d ", &v[i]);
		else
			scanf("%d ", &u[i-n]);
	}
	
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(v[i]==u[j]){
				mat[i][j]=mat[i-1][j-1]+1;
				l=mat[i][j];
			}
			else
				if(mat[i-1][j]>mat[i][j-1])
					mat[i][j]=mat[i-1][j];
				else
					mat[i][j]=mat[i][j-1];
	
	printf("%d ", l);
	
	return 0;
}
