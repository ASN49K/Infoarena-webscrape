#include <stdio.h>
#define Nmax 1024
using namespace std;
int M,N,i,j,a[Nmax],b[Nmax],lucru[Nmax][Nmax], sol[Nmax], crt;

int max (int x, int y) {if (x>y) return x; else return y;}

int main () {
	//CITIRE
	FILE *f, *g; 
	f=fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &M, &N);
	for (i=1; i<=M; i++) {fscanf(f, "%d", &a[i]); lucru[i][0]=0;}
	for (i=1; i<=N; i++) {fscanf(f, "%d", &b[i]); lucru[0][i]=0;}
	lucru[0][0]=0;
	fclose(f);
	
	g=fopen("cmlsc.out", "w");
	//FORMARE MATRICE CU FUNCTIA RECURSIVA
	for (i=1; i<=M; i++)
		for (j=1; j<=N; j++)
			if (a[i]==b[j]) lucru[i][j]=lucru[i-1][j-1]+1;
				else lucru[i][j]=max(lucru[i-1][j], lucru[i][j-1]);
	
	//FORMARE SUBSIR
	crt=0;
	for (i=M, j=N; i;)
		if (a[i]==b[j])
			sol[++crt]=a[i],i--,j--;
		else if(lucru[i-1][j]<lucru[i][j-1])
			j--;
		else 
			i--;
		
	//AFISARE
	fprintf(g, "%d\n", crt);
	for (i=crt; i>=1; i--) fprintf(g, "%d ", sol[i]);
	fclose(g);
	return 0;
}