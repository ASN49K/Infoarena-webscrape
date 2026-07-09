#include <stdio.h>
#define NM 1025
FILE *f,*g;


int a[NM],b[NM],c[NM][NM],n,m;

int main()
{
int i,j,x,y;

f=fopen("cmlsc.in","rt");
g=fopen("cmlsc.out","wt");

fscanf(f,"%d %d\n",&n,&m);

for (i=1;i<=n;i++) fscanf(f,"%d", &a[i]);
for (i=1;i<=m;i++) fscanf(f,"%d", &b[i]);

for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
       if (a[i]==b[j])  c[i][j]=c[i-1][j-1]+1;
       else
	 if (c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
	 else c[i][j]=c[i][j-1];


fprintf(g,"%d\n",c[n][m]);

x=n;
y=m;

for (i=c[n][m]; i>0; i--)
    {
    while (c[x][y]==i) x--;
    x++;
    while (c[x][y]==i) y--;
    y++;
    a[i]=b[y];
    x--;
    y--;
    }
for (i=1;i<=c[n][m];i++) fprintf(g,"%d ",a[i]);
fprintf(g,"\n");

fclose(f);
fclose(g);

return 0;
}


