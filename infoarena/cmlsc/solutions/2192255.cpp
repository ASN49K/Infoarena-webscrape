#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1025],B[1025];
int N,M;
int DP[1025][1025];
int S[1025];

void Read()
{
    fin>>M>>N;
    for(int i=1;i<=M;i++)
        fin>>A[i];
    for(int i=1;i<=N;i++)
        fin>>B[i];
}

int main()
{
    Read();

    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if (A[i] == B[j])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    int i=M,j=N;
    int k=0;
    while(i>0)
    {
        if (A[i] == B[j])
        {
            S[++k] = A[i];
            i--;
            j--;
        }
        else if (DP[i-1][j] < DP[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    fout<<k<<'\n';
    for(int i=k;i>0;i--)
        fout<<S[i]<<' ';
    return 0;
}
