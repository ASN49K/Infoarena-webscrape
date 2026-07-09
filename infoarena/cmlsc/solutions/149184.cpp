#include <stdio.h>
#define INF "cmlsc.in"
#define OUF "cmlsc.out"
const int NMAX=1025;

int nr[NMAX][NMAX]={0};
int a[NMAX],b[NMAX],n,m;
FILE *in,*out;

void preproc()
{
   int i,j;
   for(i=1;i<=n;++i)
    for(j=1;j<=m;++j)
    {
      nr[i][j]=nr[i][j-1];
      if(nr[i-1][j]>nr[i][j]) nr[i][j]=nr[i-1][j];
      if(a[i]==b[j]&&nr[i-1][j-1]+1>nr[i][j]) nr[i][j]=nr[i-1][j-1]+1;
    }
}

void recon(int i,int j)
{
  if(i>0&&j>0)
  {
     if(a[i]==b[j])
     {
	recon(i-1,j-1);
	fprintf(out,"%d ",a[i]);
     }
     else if(nr[i][j-1]>nr[i-1][j]) recon(i,j-1);
     else recon(i-1,j);
  }
}

int main()
{
   in=fopen(INF,"r");
   out=fopen(OUF,"w");
   int i,j;
   fscanf(in,"%d%d",&n,&m);
   for(i=1;i<=n;++i) fscanf(in,"%d",a+i);
   for(j=1;j<=m;++j) fscanf(in,"%d",b+j);

   preproc();
   fprintf(out,"%d\n",nr[n][m]);
   recon(n,m);

   fclose(in);fclose(out);
   return 0;
}