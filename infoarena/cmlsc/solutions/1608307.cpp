#include <stdio.h>
#include <stdlib.h>

#define max(a,b)	((a >= b) ? a : b)

int main(){
	FILE* input = fopen("cmlsc.in","r");
	FILE* output = fopen("cmlsc.out","w");

	int n,m,i,j;
	fscanf(input,"%d %d",&m,&n);
	int s1[m+1];
	int s2[n+1];
	for(i=1;i<=m;i++){
		fscanf(input,"%d",&s1[i]);
	}
	for(j=1;j<=n;j++){
		fscanf(input,"%d",&s2[j]);
	}

	int** mat;

	mat = (int**)calloc(m+1,sizeof(int*));

	for(int i=0;i<=m;i++){
		mat[i] = (int*)calloc(n+1,sizeof(int));
	}

	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s1[i] == s2[j]){
				mat[i][j] = mat[i-1][j-1] + 1;
			}
			else{
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
			}
		}
	}

	fprintf(output,"%d\n",mat[m][n]);

	int subs[mat[m][n]];
	int k = 0;
	i = m; j=n;
	while(i && j){
		if(s1[i] == s2[j]){
			subs[k] = s1[i];
			i--; j--;
			k++;
		}
		else{
			if(mat[i][j-1] > mat[i-1][j]){
				j--;
			}
			else{
				i--;
			}
		}
	}
	
	for(k=mat[m][n]-1;k>=0;k--){
		fprintf(output,"%d ",subs[k]);
	}

	for(int i=0;i<=m;i++){
		free(mat[i]);
	}
	free(mat);

	return 0;
}