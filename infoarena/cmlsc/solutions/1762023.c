#include <stdio.h>
#include <stdlib.h>
#include <string>

#define max(a,b) ((a>b?a:b))
#define MAXX 1024
int C[MAXX][MAXX]

int main(void){
	
	int n=0,m=0;
	int A[MAXX],B[MAXX],D[MAXX];
	
	FILE* f=fopen("cmlsc.in","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	
	D=(int*) malloc(1024*sizeof(int));
	
	for(int i=0;i<n;++i){
			fscanf(f,"%d",&A[i]);
		}
		for(int i=0;i<m;++i){
			fscanf(f,"%d",&B[i]);
		}
		int o=0;
		for(int i=1;i<=n;++i){		
			for(int j=1;j<=m;++j){
				if(A[i-1]==B[j-1]){
					D[o++]=A[i-1];
					C[i][j]=C[i-1][j-1]+1;
				} else {
					C[i][j]=max(C[i][j-1],C[i-1][j]);
				}
			}
		}


		fclose(f);
		f=fopen("cmlsc.out","w");

		for(int i=0;i<o;++i){
			fprintf(f,"%d ",D[i]);		
		}
		fclose(f);
}