#include <stdio.h>
#define MAX 1024
#define maxim(a,b) ((a > b) ? a : b)

using namespace std;

int M, N, A[MAX], B[MAX], D[MAX][MAX], sir[MAX], bst;

int main(void){
    int i, j;

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &M, &N);
        for(i = 1; i <= M; i++){
            scanf("%d", &A[i]);
        }


        for(i = 1; i <= N; i++){
            scanf("%d", &B[i]);
        }

        for(i = 1; i <= M; i++){
            for(j = 1; j<= N; j++){

                if(A[i] == B[j]){
                    D[i][j] = 1 + D[i-1][j-1];
                }
                else{
                    D[i][j] = maxim(D[i-1][j], D[i][j-1]);
                }
            }
        }

        for(i = M, j = N; i; ){
            if(A[i] == B[j]){
                sir[++bst] = A[i], --i, --j;

            }
            else if(D[i-1][j] < D[i][j-1])
                --j;
            else
                --i;
        }

        printf("%d\n",bst);
        for(i = bst; i ;--i){
            printf("%d ", sir[i]);
        }
    return 0;
}
