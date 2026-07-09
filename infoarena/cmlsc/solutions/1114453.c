#include <stdio.h>
#include <string.h>
#define TEXT_FILE "cmlsc"

#define FOR(i,a,b) for((i)=a;(i)<(b);(i)++)
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef unsigned short int WORD;
WORD a[1025][1025];
WORD r[1025];

int main()
{
	WORD n,m,l,i,j;
	FILE *f,*g;
	f = fopen(TEXT_FILE".in","r");
	g = fopen(TEXT_FILE".out","w");	
	fscanf(f,"%hu %hu",&n,&m);
	FOR(i,1,n+1)
		fscanf(f,"%hu",&a[i][0]);
	FOR(i,1,m+1)
		fscanf(f,"%hu",&a[0][i]);
	FOR(i,1,n+1)
	FOR(j,1,m+1)
	{
		if((i==1)||(j==1))
			a[i][j] = (a[0][j] == a[i][0]);
		else
			if(a[0][j] == a[i][0])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = MAX(a[i-1][j],a[j][i-1]);
	}
	l = a[n][m];
	i=n;
	j=m;
	while(l!=0)
	{
		if((j>1)&&(a[i][j-1] == a[i][j]))
		{
			j--;
			continue;
		}
		if((i>1)&&(a[i-1][j] == a[i][j]))
		{
			i--;
			continue;
		}
		r[l] = a[0][j];
		i--;
		j--;
		l--;
	}
	l = a[n][m];
	fprintf(g,"%d\n",l);
	FOR(i,0,l)
		fprintf(g,"%d ",r[i+1]);
}