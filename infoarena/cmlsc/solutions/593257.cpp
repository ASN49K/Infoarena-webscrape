#define i_file "cmlsc.in"
#define o_file "cmlsc.out"
#define _CRT_SECURE_NO_DEPRECATE
#define max(a,b) (a>b) ? a : b;

#include <stdio.h>
#include <stdlib.h>

int gdc(int a, int b);
int lcs(int x, int y);
void tbld();

int static  m[3],a[2][1024],b[1025][1025];

int main(int argc, char **argv, char **env)
{
	FILE * fi = fopen(i_file,"r");
	FILE * fo = fopen(o_file,"w");
	
	int *r,c,x,y;
	
	fscanf(fi,"%d%d",m,m+1);
	m[2] = max(m[0],m[1]);

	c=*m; r=a[0];
	while (c--) fscanf(fi,"%d",r++);
	c=*(m+1); r=a[1];
	while (c--) fscanf(fi,"%d",r++);

	
	c=m[3]; while (c--) {b[0][c]=0; b[c][0]=0;}

	for (y=0; y<m[1]; y++)
	for (x=0; x<m[0]; x++)
	{
		b[y+1][x+1]=lcs(x+1,y+1);
	}

    
	fprintf(fo,"%d\n",b[y][x]);
	
	c=0;
	while (b[y][x]!=0)
	{
		if (b[y-1][x]==b[y][x]) y--;
		else if (b[y][x-1]==b[y][x]) x--;
		else {y--; x--; a[0][c]=a[1][y]; c++;}
	}

	//tbld(); //debug

	while (c--)
	{
		fprintf(fo,"%d ",a[0][c]);
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}

int gdc(int a, int b)
{
	if (b == 0) return a;
	else return gdc(b, a % b);
}

int lcs(int x, int y)
{
    if (a[0][x-1] == a[1][y-1])
	{
		return b[y-1][x-1]+1;
	}
	else 
	{
		return max(b[y][x-1],b[y-1][x]);
	}

}

void tbld()
{
	int i,j,*q;
	
	for (i=0; i<=m[0]+1; i++)
	{
		i<2 ? printf("%d ",0) : printf("%d ",a[0][i-2]);
	}
	printf("\n");

	for (j=0; j<=m[1]; j++)
	{
		j==0 ? printf("%d ",0) : printf("%d ",a[1][j-1]);
		for (i=0; i<=m[0]; i++)
		{
			printf("%d ",b[j][i]);
		}
		printf("\n");
		
	}
	system("PAUSE");
}
