// Cel_mai lung_subsir_comun.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define max(a,b) ((a>b)?a:b)
int C[1024][1024];

int main(void)
{
	int n=0,m=0;
	int *A,*B,*D;
	FILE* f;
	errno_t err=fopen_s(&f,"cmlsc.in","r");
	if(err==0){		
		fscanf_s(f,"%d",&n);
		fscanf_s(f,"%d",&m);
		A=(int*) malloc(n*sizeof(int));
		B=(int*) malloc(m*sizeof(int));	
		D=(int*) malloc(1024*sizeof(int));

		for(int i=0;i<n;++i){
			fscanf_s(f,"%d",&A[i]);
		}
		for(int i=0;i<m;++i){
			fscanf_s(f,"%d",&B[i]);
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
		err=fopen_s(&f,"cmlsc.out","w");

		for(int i=0;i<o;++i){
			fprintf_s(f,"%d ",D[i]);		
		}
		fclose(f);
	} else {
		perror("");
	}

	return 0;
}

