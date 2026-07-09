#include <stdio.h>

#define LMAX 1025

#define max(a,b) (a) > (b) ? (a) : (b)

int N,M,A[LMAX],B[LMAX],T[LMAX][LMAX];

int main()
{
 freopen("cmlsc.in","r",stdin);

 scanf("%d%d",&N,&M);

 for(int i = 1;i <= N ;++i)
    scanf("%d",&A[i]);

 for(int i = 1;i <= M; ++i)
    scanf("%d",&B[i]);


 for(int i = 1;i <= N; ++i)
    for(int j = 1; j <= M; ++j)
       if(A[i] == B[j])
         T[i][j] = T[i - 1][j - 1] + 1;
        else T[i][j] = max(T[i - 1][j],T[i][j - 1]);

 freopen("cmlsc.out","w",stdout);
 printf("%d\n",T[N][M]);

 int k = T[N][M], l = N, c = M;
 while(k)
 {
  if(T[l-1][c-1] == k - 1 & T[l-1][c] == k - 1 & T[l][c-1] == k - 1)
    printf("%d ",A[l]),l--, c--, k--;
   else
     if(T[l-1][c] == k - 1) c--;
      else
        if(T[l][c-1] == k - 1) l--;
       else l--,c--;
 }


 return 0;
}


