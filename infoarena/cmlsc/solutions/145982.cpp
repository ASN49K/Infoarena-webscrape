#include<stdio.h>
FILE*fin=fopen("cmlsc.in","r");
FILE*fout=fopen("cmlsc.out","w");
#define maxn 1025
short m,n,c[maxn][maxn],tb[maxn][maxn],a[maxn],b[maxn];
void rec(int lin,int col)
{
  if(c[lin][col]>0)
  {
    if(tb[lin][col]==2)
    {
      rec(lin-1,col-1);
      fprintf(fout,"%hd%c",a[lin],' ');
    }
    else if(tb[lin][col]==1) rec(lin-1,col);
	 else rec(lin,col-1);
  }
}
int main()
{
  int i,j;
  fscanf(fin,"%hd%hd",&n,&m);
  for(i=1;i<=n;i++)
    fscanf(fin,"%hd",&a[i]);
  for(i=1;i<=m;i++)
    fscanf(fin,"%hd",&b[i]);
  fclose(fin);
  for(i=0;i<=n;i++)
    c[i][0]=0;
  for(i=1;i<=m;i++)
    c[0][i]=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    {
      c[i][j]=c[i-1][j-1]+1;
      tb[i][j]=2;
    }
    else if(c[i-1][j]>c[i][j-1])
	 {
	   c[i][j]=c[i-1][j];
	   tb[i][j]=1;
	 }
	 else
	 {
	   c[i][j]=c[i][j-1];
	   tb[i][j]=0;
	 }
  fprintf(fout,"%hd\n",c[n][m]);
  rec(n,m);
  fclose(fout);
  return 0;
}