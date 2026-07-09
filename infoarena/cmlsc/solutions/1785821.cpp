#include <cstdio>

#define maxim(a, b) ( (a>b) ? a : b)
#define NMAX 1024

using namespace std;

int A[NMAX], B[NMAX], Mat[NMAX][NMAX], CMLS[NMAX], lungime;

int main()
{
    int M, N;
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);

    for(i=1; i<=M; i++){   //citim sirul A
        scanf("%d", &A[i]);
    }
    for(i=1; i<=N; i++){   //citim sirul B
        scanf("%d", &B[i]);
    }

    for(i=1; i<=M; i++){   //cream matricea cu lungimile prefixelor
        for (int j=1; j<=N; j++){
            if(A[i]==B[j]){
                Mat[i][j] = Mat[i-1][j-1] + 1;
            } else {
                Mat[i][j] = maxim(Mat[i-1][j], Mat[i][j-1]);
            }
        }
    }

    for(i=M, j=N; i; ){   //reconstituim sirul pe baza matricei
        if (A[i]==B[j]) {
            CMLS[++lungime] = A[i];
            --i;
            --j;
        }else{
            if (Mat[i-1][j] > Mat[i][j-1]){
                --i;
            } else {
                --j;
            }
        }
    }
    printf("%d\n", lungime);    //scriem lungimea subsirului comun
    for (i=lungime; i; --i){   //scriem subsirul comun
        printf("%d ", CMLS[i]);
    }
    return 0;
}
