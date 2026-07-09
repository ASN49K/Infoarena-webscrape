#include <bits/stdc++.h>
#define Nmax 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int N, M;
short int a[Nmax];
short int b[Nmax];
short int L[Nmax][Nmax];
void rezolvare()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(a[i] == b[j])
            {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else
            {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    fout<<L[N][M]<<"\n";
    int contor = 1;
    for(int j=1; j<=M; j++)
    {
        if(L[N][j] == contor)
        {
            fout<<b[j]<<" ";
            contor++;
        }
    }
}
void citire()
{
    fin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        fin>>a[i];
    }
    for(int j=1; j<=M; j++)
    {
        fin>>b[j];
    }
    rezolvare();
}
int main()
{
    citire();
    return 0;
}
