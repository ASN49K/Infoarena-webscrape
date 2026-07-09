#include <stdio.h>

#define MAX(a,b) ((a>b) ? a : b)
#define LIM 1024

int a[LIM][LIM];

void LSC(int *A ,int m  ,int *B ,int n);
int main ()
    {
        int A[LIM],B[LIM] , i ;
        int n , m ;

        freopen("cmlsc.in","r",stdin);
        freopen("cmlsc.out","w",stdout);

        scanf ("%i %i",&m,&n);

        for( i = 1; i<=m ; i++)
            scanf("%i",&A[i]);

        for( i = 1; i<=n ; i++)
            scanf("%i",&B[i]);

        LSC(A , m , B , n);
        return 0;
    }

void LSC( int *A,int m ,int *B ,int n){

    int i , j , sol[LIM] , cnt=0;

    for ( i = 1 ; i<=m ; i++)
        for(j = 1 ;j<=n ; j++)
            if(A[i]==B[j])
                a[i][j] = a[i-1][j-1] +1;
            else
                a[i][j] = MAX(a[i-1][j],a[i][j-1]);
    for ( i=m,j=n ; i>0 && j>0 ;){
        if(A[i] == B[j]){
            sol[++cnt]=A[i];
            i--;
            j--;
        }
        else if (a[i-1][j] > a[i][j-1])
            --i;
        else
            --j;
    }
    printf("%i\n",a[m][n]);
    for(i=cnt;i > 0;i--)
        printf("%i ",sol[i]);
}
