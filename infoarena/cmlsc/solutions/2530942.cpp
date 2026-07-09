#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,A[1030],B[1030],dp[1030][1030];

int main()
{
    fin >> M >> N;
    int i,j,poz=1;
    for (i=1;i<=M;++i)
    {
        fin >> A[i];
    }
    for (i=1;i<=N;++i)
    {
        fin >> B[i];
    }
    for ()
    fin.close();
    fout.close();
    return 0;
}
