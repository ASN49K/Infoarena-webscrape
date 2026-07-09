#include <fstream>

#define NMAX 1024
#define maxim(a, b) ( (a>b) ? a : b)

using namespace std;

int main()
{
    int M, N, A[NMAX], B[NMAX], Mat[NMAX][NMAX], CMLS[NMAX];
    int i, j;
    ifstream citire("cmlsc.in");
    ofstream scriere("cmlsc.out");
    citire>>M>>N;
    for(i=1; i<=M; i++){ //citim sirul A
        citire>>A[i];
    }
    for(i=1; i<=N; i++){ //citim sirul B
        citire>>B[i];
    }
    for(i=1; i<=M; i++){ //cream matricea cu lungimile prefixelor
        for (int j=1; j<=N; j++){
            if(A[i]==B[j]){
                Mat[i][j] = Mat[i-1][j-1] + 1;
            } else {
                Mat[i][j] = maxim(Mat[i-1][j], Mat[i][j-1]);
            }
        }
    }
    int lungime=0; //lungimea subsirului comun
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
    scriere<<lungime<<"\n";       //scriem lungimea subsirului comun
    for (i=lungime; i; --i){   //scriem subsirul comun
        scriere << CMLS[i]<<" ";
    }
    return 0;
}
