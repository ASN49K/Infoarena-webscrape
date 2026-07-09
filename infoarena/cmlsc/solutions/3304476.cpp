#include <fstream>
#define NMAX 1030
using namespace std;
ifstream  fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M,N,A[NMAX],B[NMAX],dp[NMAX][NMAX];
char d[NMAX][NMAX];

void citire()
{
    fin>>M>>N;

    for(int i=1; i<=M; i++)
    {
        fin>>A[i];
    }

    for(int i=1; i<=N; i++)
    {
        fin>>B[i];
    }
}

void reconstr(int i, int j)
{
    if(!i || !j)
    {
        return;
    }

    if(d[i][j]=='N')
    {
        reconstr(i-1,j);
    }

    if(d[i][j]=='V')
    {
        reconstr(i,j-1);
    }

    if(d[i][j]=='L')
    {
        reconstr(i-1,j-1);
        fout<< A[i] << " ";
    }
}

int main()
{
    citire();

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int ok=0;
            if(A[i]==B[j])
            {
                ok=1;
            }

            dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+ok));

            if(dp[i][j]==dp[i-1][j])
            {
                d[i][j]='N';
            }
            else
            {
                if(dp[i][j]==dp[i][j-1])
                {
                    d[i][j]='V';
                }
                else
                {
                    d[i][j]='L';
                }
            }
        }
    }

    fout<< dp[M][N] << "\n";

    reconstr(M,N);

    return 0;
}
