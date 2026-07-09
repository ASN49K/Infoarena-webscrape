/*
cel mai lung subsit comun
PD
*/
#include<stdio.h>
#define MAX(a,b) ( (a) > (b) ? (a):(b) )

int a[500], b[500], sir[100]; //siruri
int n,m, best; //dimensiuni
int c[100][100];

void cit();
void rez();
void afis();


int main() {

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	cit();
	rez();
	afis();

	return 0;
}


void cit() {
	int i,j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(j=1; j<=m; j++)
		scanf("%d", &b[j]);
}


void rez() {

	int i,j,k,l;

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if( a[i] == b[j] )
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=MAX(c[i-1][j],c[i][j-1]);

	for(i=n, j=m; i; ) {
		if( a[i] == b[j] ) {
			sir[++best]=a[i];
			i--; j--;
		} else if( c[i-1][j] < c[i][j-1] )
			j--;
		else
			i--;
	}

}


void afis() {
	int i;
	printf("%d\n", best);

	for(i=best; i>0; i--)
		printf("%d ", sir[i]);
}