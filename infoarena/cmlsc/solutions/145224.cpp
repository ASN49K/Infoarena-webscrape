#include <stdio.h>

#define NMAX 1025
#define INPUT  "cmlsc.in"
#define OUTPUT "cmlsc.out"

int A[NMAX][NMAX];
char B[NMAX][NMAX];
int i,j,n,m,s1[NMAX],s2[NMAX];
int SIR[NMAX];

int main()
{
 freopen(INPUT,"r",stdin);
 freopen(OUTPUT,"w",stdout);

 scanf("%d%d",&n,&m);
 for (i=1;i<=n;i++)
    scanf("%d",&s1[i]);
 for (i=1;i<=m;i++)
    scanf("%d",&s2[i]);

 for (i=1;i<=n;i++)
 for (j=1;j<=m;j++)
    if (s1[i]==s2[j])
      {
       A[i][j]=1+A[i-1][j-1];
       B[i][j]=1;
      }
      else if (A[i-1][j]>A[i][j-1])
             {
              A[i][j]=A[i-1][j];
              B[i][j]=2;
             }
      else if (A[i-1][j]<=A[i][j-1])
             {
              A[i][j]=A[i][j-1];
              B[i][j]=3;
             }
 printf("%d\n",A[n][m]);
 int x=n,y=m;
 while (x != 0 && y != 0)
      {
       if (s1[x]==s2[y])
         SIR[++SIR[0]]=s1[x];
       if (B[x][y]==1) {x--;y--;}
         else if (B[x][y]==2) {x--;}
         else y--;
      }
 for (i=SIR[0];i>=1;i--)
    printf("%d ",SIR[i]);

 fclose(stdin);
 fclose(stdout);
 return 0;
}

