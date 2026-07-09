#include <stdio.h>
#define maxim(a, b) ((a > b) ? a : b)

int m,n,i,j,A[1024],B[1024],Rez[1024],Mat[1024][1024],len=0;

int main(void){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf ("%d %d",&m,&n);

    for (i=1;i<=m;++i)
        scanf("%d", &A[i]);

    for (i=1;i<=n;++i)
        scanf("%d", &B[i]);

    for (i=1;i<=m;++i)
        for(j=1;j<=n;++j)
            if(A[i]==B[j])
                Mat[i][j]= 1+Mat[i-1][j-1];
            else
                Mat[i][j] = maxim(Mat[i-1][j], Mat[i][j-1]);


     i=m;
     j=n;
     while (i)
        if (A[i] == B[j]){
            Rez[++len] = A[i];
            --i;
            --j;}
        else if (Mat[i-1][j] < Mat[i][j-1])
            --j;
        else
            --i;


      printf("%d\n", len);
      for (i = len; i; --i)
          printf("%d ", Rez[i]);

      return 0;}
