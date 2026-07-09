#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

FILE* f;
FILE* g;
int i,j,n,m;
int v1[1200], v2[1200];
int P[1200][1200];
int prevI[1200][1200],prevJ[1200][1200];
int print[1200][1200]; 

void printresult(int x, int y) {
	if (x>0 && y>0) {
		printresult(prevI[x][y],prevJ[x][y]);
		
		
	
		if (print[x][y]!=-1) {
			fprintf(g,"%d ",print[x][y]);
		}
	}
}

int main(int argc, char **argv)
{
	f = fopen("cmlsc.in","r");
	g = fopen("cmlsc.out","w");
	
	fscanf(f,"%d%d",&n,&m);
	
	for (int i=1;i<=n;i++) {
		fscanf(f,"%d",&v1[i]);
		P[i][0]=0;
	}
	for (int i=1;i<=m;i++) {
		fscanf(f,"%d",&v2[i]);
		P[0][i]=0;
	}
	
	int val;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			print[i][j]=-1;
			val = P[i-1][j-1];
			
			if (v1[i]==v2[j]) {
				val += 1;
				print[i][j]=v1[i]; 
			}
				
			if (val>P[i-1][j] && val>P[i][j-1]) {
				P[i][j]=val;
				prevI[i][j]=i-1;
				prevJ[i][j]=j-1;
			}
			else if (P[i-1][j]>P[i][j-1]) {
				P[i][j]=P[i-1][j];
				prevI[i][j]=i-1;
				prevJ[i][j]=j;
				print[i][j]=-1;
			} else {
				P[i][j]=P[i][j-1];
				prevI[i][j]=i;
				prevJ[i][j]=j-1;
				print[i][j]=-1;
			}
			
		}
	}
	
	fprintf(g,"%d\n",P[n][m]);
	printresult(n,m);

	fclose(f);
	fclose(g);
	return 0;
}
