#include <stdio.h>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define max 111

FILE *fin=fopen(IN,"r");
FILE *fout=fopen(OUT,"w");

long a[max], b[max];
long v[max][max];
long sol[max];
int m,n,s;

long maxim(long,long);
void citire();
void afis();
void alg();

int main()
{
 citire();
  fclose(fin);

  alg();

 afis();
  fclose(fout);

return 0;
}

void citire()
{
 int i,j;

 fscanf(fin,"%d %d/n",&n,&m);

 for(i=1;i<=n;i++)
  fscanf(fin,"%ld",&a[i]);

 for(j=1;j<=m;j++)
  fscanf(fin,"%ld",&b[j]);
}

long maxim(long a,long b)
{
 if(a>b)
  return a;
return b;
}

void afis()
{
 int i;

 fprintf(fout,"%d\n",s);
 for (i=s;i>=1;i--)
  fprintf(fout,"%ld ",sol[i]);
}

void alg()
{
 int i,j;

 for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
   if(a[j]==b[i])
    v[i][j]=v[i-1][j-1]+1;
   else
    v[i][j]=maxim(v[i][j-1],v[i-1][j]);

 s=v[m][n];

 int x=m,y=n;

 for(i=1;i<=s;i++)
 {
  while(a[y]!=b[x])
  {
   if(v[x][y]==v[x][y-1])
    y--;
   if (v[x][y]==v[x-1][y])
    x--;
  }

  sol[i]=a[y];
  x--;
  y--;
 }
}
