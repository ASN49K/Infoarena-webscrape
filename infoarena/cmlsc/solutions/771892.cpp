#include <fstream>
#include <iostream>
using namespace std;
int i,j,lgx,lgy,x[1024],y[1024],m[1024][1024],subsir[1024],lgs;

int max (int a, int b)
{
	if (a>b) return a;
	else return b;
}

int main () {
	//CITIRE
	FILE *f,*g;
	f=fopen("cmlsc.in", "r");
	g=fopen("cmlsc.out", "w");
	fscanf(f, "%d %d", &lgx, &lgy);cout<<lgx<<" "<<lgy;
	for (i=1; i<=lgx; i++) fscanf(f, "%d", &x[i]);
	for (i=1; i<=lgy; i++) fscanf(f, "%d", &y[i]);
	
	//FORMARE MATRICE CU FUNCTIA DE RECURENTA
	for (i=1; i<=lgx; i++)
		for (j=1; j<=lgy; j++)
			if (x[i]==y[j]) m[i][j]=m[i-1][j-1]+1;
			else m[i][j]=max(m[i-1][j], m[i][j-1]);
			
	//FORMARE SUBSIR
	for (i=lgx, j=lgy; i>0, j>0;)
		if (x[i]==y[j]) subsir[++lgs]=x[i],i--,j--;
		else if (m[i][j-1]>m[i-1][j]) j--;
				else i--;
	//AFISARE
	fprintf(g, "%d\n", lgs);
	for (i=lgs; i>0; i--) fprintf(g, "%d ", subsir[i]);
	fclose(f); fclose(g);
	return 0;
}