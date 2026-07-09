#include <stdio.h>
#include <fstream>

int M,N;
int A[1024],B[1024],C[1024];

 int main() {
     int i,j,k=0,ant=0;
     freopen("cmlsc.in","r",stdin);
     freopen("cmlsc.out","w",stdout);
     scanf("%d %d",&M,&N);
     for (i = 1; i <= M; i++)
         scanf("%d", &A[i]);
     for (i = 1; i <=N; i++)
         scanf("%d", &B[i]);
     for (i=1;i<=M;i++)
        for (j=1;j<=N;j++){
            if (A[i]==B[j] && j>ant){
                ant=j;
                k++;
                C[k]=A[i];
            }
     }
    printf("%d\n",k);
    for (i=1;i<=k;i++)
        printf("%d ",C[i]);
 	return 0;
  }

