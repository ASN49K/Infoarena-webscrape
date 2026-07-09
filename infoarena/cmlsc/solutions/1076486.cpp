#include <iostream>
#include <fstream>
#define LMax 1024
#define Max(a,b) a >= b ? a : b

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int M, N, A[LMax], B[LMax], Tabel[LMax][LMax];

void ConstruireTabel()
{
    for(short int i=1; i<=M; ++i)
        for(short int j=1; j<=N; ++j)
        {
            if(A[i]==B[j])
                Tabel[i][j]=Tabel[i-1][j-1]+1;
            else Tabel[i][j]=Max(Tabel[i-1][j], Tabel[i][j-1]);
        }

    fout<<Tabel[M][N]<<'\n';
}

void ReconstruireTabel()
{
    short int k=Tabel[M][N], C[k];

    short int i=M, j=N;

    do
    {
        if(A[i]==B[j]) {C[k--]=A[i]; i--; j--;}
        else if (Tabel[i-1][j]>Tabel[i][j-1]) i--;
        else j--;
    }
    while(k);

    for(i=1; i<=Tabel[M][N]; ++i)
        fout<<C[i]<<' ';
}

int main()
{
    fin>>M>>N;

    for(short int i=1; i<=M; ++i)
        fin>>A[i];
    for(short int j=1; j<=N; ++j)
        fin>>B[j];

    ConstruireTabel();
    ReconstruireTabel();

}
