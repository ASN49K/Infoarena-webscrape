#include <cstdio>
#define NMax 1026
#define MAX(a,b)((a)>(b)?(a):(b))

int best[NMax][NMax];
int A[NMax];
int B[NMax];

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int i,j,N,M,lgmax;

    scanf("%d %d",&N,&M);
    for( i = 1; i <= N; ++i ) scanf("%d",&A[i]);
    for( j = 1; j <= M; ++j ) scanf("%d",&B[j]);

    for( i = N; i >= 1; --i )
        for( j = M; j >= 1; --j )
        {
            if( A[i] == B[j] ) best[i][j] = 1 + best[i+1][j+1];
            else best[i][j] = MAX( best[i][j+1], best[i+1][j] );
        }

    printf("%d\n",best[1][1]);

    for( lgmax = 0, i = 1, j = 1; lgmax < best[1][1]; )
    if( A[i] == B[j] ) { printf("%d ",A[i]); ++lgmax; ++i; ++j; }
    else if( best[i+1][j] > best[i][j+1] ) ++i;
    else ++j;


return 0;
}
