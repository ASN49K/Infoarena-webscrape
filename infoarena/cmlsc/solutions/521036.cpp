#include<cstdio>
#include<cstdlib>
using namespace std;

int *a,*b;
int n,m;
int **mat;

void computeMatrix(){
	int i,j;
	
	for (i = 0; i <= n; i++) {
		mat[i][0] = 0;		
	}
	
	for (i = 0; i <= m; i++) {
		mat[0][i] = 0;		
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			mat[i][j] = 0;
			if (a[i-1] == b[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
			else mat[i][j] = (mat[i-1][j] > mat[i][j-1])?mat[i-1][j]:mat[i][j-1];
		}
	}	
}

void computeSol(int val, int i, int j){
	if (val == 0) return;
	if (mat[i][j] == mat[i-1][j-1] + 1) {
		computeSol(val-1,i-1,j-1);
		printf("%d ",a[i-1]);
	}
	else if(mat[i-1][j] < mat[i][j-1]) computeSol(val, i, j-1);
		else computeSol(val, i-1, j);
}
int main() {

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d\n", &n, &m);
	a = (int *)malloc(n * sizeof(int));	
	b = (int *)malloc(m * sizeof(int));
	
	mat = (int **)malloc((n+1) * sizeof(int *));
	int i;
	for (i = 0; i <= n; i++) {
		mat[i] = (int *)malloc((m+1) * sizeof(int));
	}
	
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	for (i = 0; i < m; i++)
		scanf("%d",&b[i]);	
	
	computeMatrix();
	printf("%d\n",mat[n][m]);
	computeSol(mat[n][m], n, m);
	printf("\n");

	free(a);
	free(b);		
	for (i = 0; i < n; i++) free(mat[i]);
	
	free(mat);
	return 0;
}