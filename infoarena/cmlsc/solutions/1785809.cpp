#include <fstream>
#include <iostream>

#define maxim(a, b) ( (a>b) ? a : b)

using namespace std;

int main()
{
    int M, N;
    int i, j;
    ifstream citire("cmlsc.in");
    ofstream scriere("cmlsc.out");

    citire>>M>>N;
    int A[M+1], B[N+1], Mat[M+1][N+1], CMLS[maxim(M,N)+1];
    Mat[0][0]=0;           //initializam cu 0 prima linie si coloana
    for(i=1; i<=M; i++){   //citim sirul A
        citire>>A[i];
        Mat[i][0]=0;       //initializam cu 0 prima linie si coloana
    }
    for(i=1; i<=N; i++){   //citim sirul B
        citire>>B[i];
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
    scriere<<lungime<<"\n";    //scriem lungimea subsirului comun
    for (i=lungime; i; --i){   //scriem subsirul comun
        scriere << CMLS[i]<<" ";
    }
    return 0;
}
