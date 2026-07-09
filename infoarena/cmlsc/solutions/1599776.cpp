#include <iostream>
#include <fstream>
#define NMax 1024
#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], c =0;

int main() {

    fstream f("cmlsc.in",ios::in);
    fstream g("cmlsc.out",ios::out);

    f >> M >> N;

    for(int i=1;i<=M;i++)
        f>>A[i];

    for(int i=1;i<=N;i++)
        f>>B[i];

    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            if(A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);

    int j;
     for (int i = M, j = N; i; )
        if (A[i] == B[j]) {
            sir[++c] = A[i];
            --i;
            --j;
        }
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

     for (int i = c; i ; --i)
        g << sir[i]<< " ";

}
