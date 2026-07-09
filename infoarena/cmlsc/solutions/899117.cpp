#include <iostream>
#include <fstream>
#define LMax 1026

using namespace std;
int M,N,Aux=1,A[LMax],B[LMax],C[LMax];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    fin>>M>>N;

    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
    {
        fin>>B[i];
        for(int j=1;j<=M;j++)
            if(B[i]==A[j]) C[Aux++]=B[i];
    }
    fout<<Aux-1<<'\n';
    for(int i=1;i<Aux;i++)
        fout<<C[i]<<' ';
}
