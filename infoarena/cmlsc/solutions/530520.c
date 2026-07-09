/*
 ============================================================================
 Name        : subsircomun.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int min ( int a, int b ){
	if ( a<b){
		return a; 
	} else{
		return b; 
	}
}

int max ( int a, int b ){
	if ( a>b ){
		return a; 
	} else {
		return b; 
	}
}

int main(void) {
	
	FILE * in = fopen("cmlsc.in","r");
	FILE * out = fopen("cmlsc.out","w");
	
	int m,n; 
	fscanf(in,"%d%d",&m,&n); 
	int *a, *b; 
	a = calloc(m,sizeof(int));
	b = calloc(n, sizeof(int)); 
	
	int i; 
	for ( i=0; i<m; i++){
		fscanf(in,"%d",&a[i]); 
	}
	for ( i=0; i<n; i++){
		fscanf(in,"%d",&b[i]); 
	}
	
	
	int ** dp = NULL; 
	dp = calloc(m+1,sizeof(int*)); 
	for ( i=0; i<=m; i++){
		dp[i] = calloc(n+1,sizeof(int));
	}
	int j; 
	for ( i=1; i<=m; i++){
		for ( j=1; j<=n; j++){
			if ( a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1] +1; 
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
				
			}
			//printf(" %d ",dp[i][j]); 
		}
		//printf("\n"); 
	}
	
	i = m; 
	j = n; 
	int * stack = calloc( 1028, sizeof(int)); 
	int cap = -1; 
	while ( i>0 && j>0){
	//printf("%d %d\n",i,j); 
		if ( a[i-1] == b[j-1]){
			cap++; 
			stack[cap] = a[i-1]; 
			i--; 
			j--; 
		} else{
			if ( dp[i-1][j]>dp[i][j-1]){
				i--; 
			} else{
				j--; 
			}
		}
	}
	fprintf(out,"%d\n",dp[m][n]); 
	
	while ( cap>=0){
		fprintf( out, "%d ",stack[cap]);
		cap--; 
	}
	
	free( stack ); 
	
	for ( i=0; i<=m; i++){
		free( dp[i]); 
	}
	free(dp); 
	
	free( b ); 
	free( a ); 
	
	fclose( in ); 
	fclose( out ); 
	return 0; 
}



