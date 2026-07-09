#include <fstream>

#define NMAX 1024
#define maxim(a, b) ( (a>b) ? a : b)

using namespace std;

int main()
{
    int M, N, A[NMAX], B[NMAX], Mat[NMAX][NMAX], CMLS[NMAX];
    ifstream citire("cmlsc.in");
    ofstream scriere("cmlsc.out");
    citire>>M>>N;
    for(int i=1; i<=M; i++){ //citim sirul A
        citire>>A[i];
    }
    for(int i=1; i<=N; i++){ //citim sirul B
        citire>>B[i];
    }
    for(int i=1; i<=M; i++){ //cream matricea cu lungimile prefixelor
        for (int j=1; j<=N; j++){
            if(A[i]==B[j]){
                Mat[i][j] = Mat[i-1][j-1] + 1;
            } else {
                Mat[i][j] = maxim(Mat[i-1][j], Mat[i][j-1]);
            }
        }
    }
    int lungime=0; //lungimea subsirului comun
    for( ; M; ){   //reconstituim sirul pe baza matricei
        if (A[M]==B[N]) {
            CMLS[++lungime] = A[M];
            --M;
            --N;
        }else{
            if (Mat[M-1][N] > Mat[M][N-1]){
                --M;
            } else {
                --N;
            }
        }
    }
    scriere<<lungime<<endl;       //scriem lungimea subsirului comun
    for (; lungime; --lungime){   //scriem subsirul comun
        scriere << CMLS[lungime]<<" ";
    }
    return 0;
}
