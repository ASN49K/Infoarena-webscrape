#include <cstdio>
#include <cstring>

using namespace std;

#define NMAX 1025
#define max(a,b) ((a>b) ? a : b)

int A[NMAX],B[NMAX],sol[NMAX];
int D[NMAX][NMAX];

void Cmlsc(int A[],int B[])
{
    int i,j;

    memset(sol,0,sizeof(sol));

    for (i=1;i<=A[0];++i)
      for (j=1;j<=B[0];++j)
      {
          if (A[i]==B[j])
          {
              D[i][j]=D[i-1][j-1]+1;
              continue;
          }

          D[i][j]=max(D[i-1][j],D[i][j-1]);
      }

    i=A[0];
    j=B[0];

    while (i && j)
    {
        if (A[i]==B[j])
        {
            sol[++sol[0]]=A[i];
            --i,--j;
            continue;
        }

        if (D[i-1][j]>D[i][j-1])
        {
            --i;
            continue;
        }

        --j;
    }

   printf("%d\n",sol[0]);
   for (i=sol[0];i>=1;--i) printf("%d ",sol[i]);
   printf("\n");
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d%d",&A[0],&B[0]);
for (int i=1;i<=A[0];++i) scanf("%d",&A[i]);
for (int i=1;i<=B[0];++i) scanf("%d",&B[i]);

Cmlsc(A,B);

return 0;
}
