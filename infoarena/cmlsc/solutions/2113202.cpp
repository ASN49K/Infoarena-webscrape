#include <iostream>
#include <fstream>
#define MAX 1030

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N,M;
int A[MAX];
int B[MAX];
int D[MAX][MAX];

void Read()
{
    in >> N >> M ;

    for ( int i = 1; i <= N ; ++i) in >> A[i];

    for ( int i = 1; i <= M ; ++i) in >> B[i];

    for ( int i = 1; i <= N ; ++i)
        for ( int j = 1; j <= M ; ++j)
        if(A[i] == B[j])
        D[i][j] = D[i-1][j-1] + 1;
         else D[i][j] =max(D[i-1][j] , D[i][j-1]);
}

void Rezolv()
{
    int i,j,T[MAX],k;


    k = 0;
    i = N ;
    j = M;

    while ( i > 0 && j > 0)
    {
        if ( A[i] == B[j])
        {
            T[++k] = A[i];
            i--;
            j--;
        }

        else if( D[i][j-1] > D[i-1][j]) j--;
              else i--;
    }

    out << k <<"\n";
    for ( i = k ; i >= 1 ; i--)
        out << T[i] <<" ";

}


int main()
{
    Read();
    Rezolv();


    return 0;
}


