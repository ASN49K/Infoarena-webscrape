#include <iostream>
#include <fstream>
#define LMax 1024
#define Max(a,b) a >= b ? a : b

using namespace std;
int M,N,Aux=1,A[LMax],B[LMax],C[LMax],Tablou[LMax][LMax];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void Citire()
{
    fin>>M>>N;

    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
}

void RezolvareTablou()
{
    for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
    {
        if (A[i]==B[j])
            Tablou[i][j]=Tablou[i-1][j-1]+1;
        else Tablou[i][j]=Max(Tablou[i-1][j],Tablou[i][j-1]);
    }

    fout<<Tablou[M][N]<<'\n';
}

void ReconstruireCMLSC()
{
    int i=M, j=N, k=Tablou[M][N];
    while(i && j)
        if (A[i]==B[j])
        {
            C[k--]=A[i];
            i--;
            j--;
        }
        else if(Tablou[i-1][j]<Tablou[i][j-1]) j--;
            else i--;
}

int main()
{
    Citire();
    RezolvareTablou();
    ReconstruireCMLSC();

    for(int i=1;i<=Tablou[M][N];i++) fout<<C[i]<<' ';
}
