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
    vector<short int>sir;
    int i = N, j = M;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            sir.push_back(b[j]);
            i--;
            j--;
        }
        if(L[i-1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    for(int i = sir.size() - 1; i>=0; i--)
        fout<<sir[i]<<" ";
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
