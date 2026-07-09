#include <stdio.h>
#include <string.h>
#define TEXT_FILE "cmlsc"

#define FOR(i,a,b) for((i)=a;(i)<(b);(i)++)
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef unsigned short int WORD;
WORD x[1024];
WORD y[1024];
WORD a[1024][1024];
WORD r[1024];

int main()
{
	WORD n,m,l,i,j;
	FILE *f,*g;
	f = fopen(TEXT_FILE".in","r");
	g = fopen(TEXT_FILE".out","w");	
	fscanf(f,"%hu %hu",&n,&m);
	FOR(i,0,n)
		fscanf(f,"%hu",&x[i]);
	FOR(i,0,m)
		fscanf(f,"%hu",&y[i]);
	a[0][0] = (x[0] == y[0]);
	FOR(i,1,n)
		if(x[i] == y[0])
			a[i][0] = 1;
		else
			a[i][0] = a[i-1][0];
	FOR(i,1,m)
		if(y[i] == x[0])
			a[0][i] = 1;
		else
			a[0][i] = a[0][i-1];
	FOR(i,1,n)
		FOR(j,1,m)
			if(x[i] == y[j])
				a[i][j] = MAX(a[i-1][j-1] + 1,MAX(a[i-1][j],a[j][i-1]));
			else
				a[i][j] = MAX(a[i-1][j],a[i][j-1]);
	l = a[n-1][m-1];
	i=n-1;
	j=m-1;
	while(l!=0)
	{
		if((j>0)&&(a[i][j-1] == a[i][j]))
		{
			j--;
			continue;
		}
		if((i>0)&&(a[i-1][j] == a[i][j]))
		{
			i--;
			continue;
		}
		r[--l] = x[i];
		i--;
		j--;
	}
	l = a[n-1][m-1];
	fprintf(g,"%d\n",l);
	FOR(i,0,l)
		fprintf(g,"%d ",r[i]);
}