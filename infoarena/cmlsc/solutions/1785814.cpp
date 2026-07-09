#include <cstdio>

#define maxim(a, b) ( (a>b) ? a : b)

using namespace std;

int main()
{
    int M, N;
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    int A[M+1], B[N+1], Mat[M+1][N+1], CMLS[maxim(M,N)+1];
    Mat[0][0]=0;           //initializam cu 0 prima linie si coloana
    for(i=1; i<=M; i++){   //citim sirul A
        scanf("%d", &A[i]);
        Mat[i][0]=0;       //initializam cu 0 prima linie si coloana
    }
    for(i=1; i<=N; i++){   //citim sirul B
        scanf("%d", &B[i]);
        Mat[0][i]=0;       //initializam cu 0 prima linie si coloana
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
    int lungime=0;        //lungimea subsirului comun
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
