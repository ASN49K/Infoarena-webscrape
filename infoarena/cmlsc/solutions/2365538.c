#include <stdlib.h>
#include <stdio.h>
#define SIZE 1024
short a[SIZE], b[SIZE], sol[SIZE];

int max(int nr1, int nr2){return nr1>nr2?nr1:nr2; }

int lcs(int m, int n){
	int lcs[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
			}
			else if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	int k = lcs[m][n]-1;
	int i = m;
	int j = n;
	while(i >= 1 && j >= 1){
		if(lcs[i][j] != max(lcs[i-1][j], lcs[i][j-1])){
				sol[k--] = a[i-1];
				i--;
				j--;
		}
		else if(lcs[i-1][j] > lcs[i][j-1]){
				i--;
			}else
				j--;
	}
	
	return lcs[m][n];
}


int main(){

	FILE *ptr, *ptrO;
	ptr = fopen("cmlsc.in", "r");
	ptrO = fopen("cmlsc.out", "w");
	int m = 0, n=0;
	fscanf(ptr, "%d %d", &m, &n);
	for(int i=0;i<m;i++)
		fscanf(ptr,"%d ", &a[i]);
	for(int i=0;i<n;i++)
		fscanf(ptr,"%d ", &b[i]);

	int l = lcs(m, n);
	fprintf(ptrO, "%d\n", l);
	for(int i=0;i<l;i++)
		fprintf(ptrO, "%d ", sol[i]);
	fclose(ptr);
	fclose(ptrO);
	return 0;
}