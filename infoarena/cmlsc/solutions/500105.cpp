#include<stdio.h>

#define dim 1050

FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");

int max( int a, int b ){
	
	if ( a > b )
		return a;
	return b;
	
}

int N,M,i,j,A[dim],B[dim],suf[dim][dim],sol[dim],k;


int main () {
	
	fscanf(f,"%d %d",&N,&M);
	
	for ( i = 1 ; i <= N ; ++i )
		fscanf(f,"%d",&A[i]);
	for ( j = 1 ; j <= M ; ++j )
		fscanf(f,"%d",&B[j]);
	
	for ( i = 1 ; i <= N ; ++i ){
		for ( j = 1 ; j <= M ; ++j )
			if ( A[i] == B[j] )
				suf[i][j] = suf[i-1][j+1] + 1 ;
			else
				suf[i][j] = max( suf[i-1][j] , suf[i][j-1] );
	}
	
	for ( i = N , j = M ; i > 0 ; ){
		if ( A[i] == B[j] )
			sol[++k] = A[i--], --j;
		else
			if ( suf[i-1][j] > suf[i][j-1] )
				--i;
			else
				--j;
		
	}
	
	fprintf(g,"%d\n",k);
	
	for ( i = k ; i >= 1 ; --i )
		fprintf(g,"%d ",sol[i]);
	
	fprintf(g,"\n");
	
	fclose(f);
	fclose(g);
	
	return 0;
	
}
