#include <stdio.h>
#include <fstream>

#define NMAX 1024
#define max(a,b) ((a>b) ? a : b)

int M,N;
int A[NMAX],B[NMAX],C[NMAX][NMAX],sir[NMAX];

int main() {
    int i,j,lun=0;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&M,&N);
    for (i = 1; i <= M; ++i)
         scanf("%d", &A[i]);
    for (i = 1; i <=N; ++i)
         scanf("%d", &B[i]);
    for (i=1;i<=M;++i)
        for (j=1;j<=N;++j)
            if (A[i]==B[j])
                C[i][j]=1+C[i-1][j-1];
        else
            C[i][j]=max(C[i-1][j],C[i][j-1]);
    for (i=M,j=N;i,j;)
        if (A[i]==B[j]){
            sir[++lun]=A[i];
            --i;
            --j;
        }
        else if (C[i-1][j]<C[i][j-1])
            --j;
        else
            --i;
    printf("%d\n",lun);
    for (i=lun;i;--i)
        printf("%d ",sir[i]);
 	return 0;
  }

