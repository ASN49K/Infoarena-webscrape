#include <cstdio>
#define infile "cmlsc.in"
#define outfile "cmlsc.out"
#define MaxN 1025

int c[MaxN][MaxN];
int N,M,a[MaxN],b[MaxN];
int max,pozi,pozj;

void read()
{
      int i;
      scanf("%d%d",&N,&M);
      for(i=1;i<=N;i++)
            scanf("%d",&a[i]);
      for(i=1;i<=M;i++)
            scanf("%d",&b[i]);
}

void solve()
{
      int i,j;

      for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
            {
                  if(a[i]==b[j])
                        c[i][j]=c[i-1][j-1]+1;
                  else
                        if(c[i-1][j]>c[i][j-1])
                              c[i][j]=c[i-1][j];
                        else
                              c[i][j]=c[i][j-1];

                  if(c[i][j]>max)
                        max=c[i][j], pozi=i, pozj=j;
            }
}

void writer(int i,int j)
{
      if(i && j)
      {
            if(a[i]==b[j])
                  writer(i-1,j-1);
            else
                  if(c[i-1][j]>c[i][j-1])
                        writer(i-1,j);
                  else
                        writer(i,j-1);
            if(a[i]==b[j])
                  printf("%d ",a[i]);
      }
}

void write()
{
      printf("%d\n",max);
      writer(pozi,pozj);
}

int main()
{
      freopen(infile,"r",stdin);
      freopen(outfile,"w",stdout);

      read();
      solve();
      write();

      fclose(stdin);
      fclose(stdout);
      return 0;
}
