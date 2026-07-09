#include<stdio.h>
#include<algorithm>
#define nmax 1030
using namespace std;

int a[nmax], b[nmax], m[nmax][nmax], A, B, i, j, lg;
FILE *g = fopen("cmlsc.out","w");

void drum(int i, int j){

	if(m[i][j] == 0)
		return;	
	
	if( a[i] == b[j]){
		drum(i-1, j-1);
		fprintf(g,"%d ",a[i]);
	}
	
	else
		if(m[i-1][j] > m[i][j-1])
			drum(i-1, j);
		
		else
			drum(i, j-1);

}

int main(){

	FILE *f = fopen("cmlsc.in","r");
	
	fscanf(f,"%d %d",&A,&B);
	for(i=1; i <= A; i++)
		fscanf(f,"%d",&a[i]);
	
	for(i=1; i <= B; i++)
		fscanf(f,"%d",&b[i]);
	
	for(i=1; i<=A; i++)
		for(j=1; j<=B; j++)
			if( a[i] == b[j] )
				m[i][j] = m[i-1][j-1] + 1;
			
			else
				m[i][j] = max(m[i][j-1], m[i-1][j] );			
	
	lg = m[A][B];
	fprintf(g,"%d\n",m[A][B]);	
	drum(A,B);
	
	fclose(f);
	fclose(g);
	
	return 0;
}
