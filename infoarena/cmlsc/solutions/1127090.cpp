/*
    Keep It Simple!
*/

#include<stdio.h>

#define Max(a,b) (a>b?a:b)

int n,m,v1[1025],v2[1025],mat[1025][1025],Final[1025],nrf;


void Compute_lcs()
{
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(v1[i] == v2[j])
          mat[i][j] = mat[i-1][j-1]+1;
        else
          mat[i][j] = Max(mat[i-1][j],mat[i][j-1]);
}

void Print_lcs()
{
    int i = n,j = m;

    while( i && j )
    {
       if(v1[i] == v2[j]) { Final[++nrf] = v1[i]; i--; j--;}
       else if( mat[i-1][j] > mat[i][j-1] ) i--;
       else j--;
    }

    for(int i=nrf;i>0;i--)
      printf("%d ",Final[i]);
}

int main()
{
   freopen("cmlsc.in","r",stdin);
   freopen("cmlsc.out","w",stdout);

   scanf("%d%d",&n,&m);

   for(int i=1;i<=n;i++)
     scanf("%d",&v1[i]);
   for(int i=1;i<=m;i++)
     scanf("%d",&v2[i]);

    Compute_lcs();
    printf("%d\n",mat[n][m]);

    Print_lcs();
}
