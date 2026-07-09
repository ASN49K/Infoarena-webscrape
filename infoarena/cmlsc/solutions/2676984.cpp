#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void citire();
int M, N, A[NMAX], B[NMAX], str[NMAX], D[NMAX][NMAX];
int k;
int main()
{
    int i, j;
    f>>M>>N;
    for(i=1; i<=M; i++)
        f>>A[i];
    for(i=1; i<=N; i++)
        f>>B[i];
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            if(A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else if(D[i-1][j] > D[i][j-1]) D[i][j]=D[i-1][j];
            else D[i][j]=D[i][j-1];
    for(i=M, j=N; i; )
        if(A[i] == B[j])
        {
            str[++k]=A[i];
            --i;
            --j;
        }
        else if(D[i-1][j]>D[i][j-1])
            --i;
        else --j;
    citire();
    return 0;
}
void citire()
{
    g<<k<<endl;
    while(k) {
        g<<str[k]<<" "; --k;
    }
}
