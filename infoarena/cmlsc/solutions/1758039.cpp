#include<iostream>
#include<fstream>
#define NMax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,Max;
int A[NMax],B[NMax],Sol[NMax];
int DP[NMax][NMax];

void Read()
{
    fin>>M>>N;

    for(int i = 1 ; i <= M ; ++i)
        fin>>A[i];

    for(int i = 1 ; i <= N ; ++i)
        fin>>B[i];
}

void Solve()
{
    int i,j;

    for(i = 1 ; i <= M ; ++i)
        for(j = 1 ; j <= N ; ++j)
            if( A[i] == B[j] )  DP[i][j] = DP[i-1][j-1] + 1;
            else    DP[i][j] = max(DP[i-1][j],DP[i][j-1]);

    for(i = M , j = N; i ; )
        if( A[i] == B[j] )  {   Sol[++Max] = A[i];  i--; j--;   }
        else
            if( DP[i-1][j] < DP[i][j-1] )   j--;
            else    i--;
}

void Print()
{
    fout<<Max<<"\n";

    for(int i = Max ; i >= 1 ; i--)
        fout<<Sol[i]<<" ";
}

int main()
{
    Read();
    Solve();
    Print();

    return 0;
}
