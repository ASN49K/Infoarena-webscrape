#include<stdio.h>
#include<stdlib.h>

#define d 1025
int mat[d][d];
FILE *g;

void drum(int i,int j,int *a,int *b){
	if(i == 0 || j == 0)
		return;
	if(a[i] == b[j]){
		drum(i - 1,j - 1,a,b);
		fprintf(g,"%d ",a[i]);
	}
	else 
		if(mat[i][j - 1] >= mat[i - 1][j])
			drum(i,j - 1,a,b);
		else
			drum(i - 1,j,a,b);
}

int max(int a,int b){
	return a > b ? a : b;
}

int cmlsc(int *a,int *b,int n,int m){
	int i,j;
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m;j++){
			if(a[i] != b[j])
				mat[i][j] = max(mat[i][j - 1],mat[i - 1][j]);
			else
				mat[i][j] = 1 + mat[i - 1][j - 1];
		}
	return mat[n][m];
}

int main(){
	FILE *f;
	f = fopen("cmlsc.in","r");
	g = fopen("cmlsc.out","w");
	int n,m,*a,*b,i;
	fscanf(f,"%d%d",&n,&m);
	a = (int*)malloc((n+1) * sizeof(int));
	b = (int*)malloc((m+1) * sizeof(int));
	for(i = 1;i <= n;i++)
		fscanf(f,"%d",&a[i]);
	for(i = 1;i <= m;i++)
		fscanf(f,"%d",&b[i]);
	int lung = cmlsc(a,b,n,m);
	fprintf(g,"%d\n",lung);
	drum(n,m,a,b);
	free(a);
	free(b);
	fclose(f);
	fclose(g);
	return 0;
}
