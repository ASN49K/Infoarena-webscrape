#include <fstream>
#define NMAX 1030
using namespace std;
ifstream  fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M,N,A[NMAX],B[NMAX],dp[NMAX][NMAX];
char fw[NMAX][NMAX];

void citire()
{
    fin>>M>>N;

    for(int i=1; i<=M; i++)
    {
        fin>>A[i];
    }

    for(int j=1; j<=N; j++)
    {
        fin>>B[j];
    }
}

void refacere_drum(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }

    if(fw[i][j]=='s')
    {
        refacere_drum(i-1,j);
    }

    if(fw[i][j]=='e')
    {
        refacere_drum(i,j-1);
    }

    if(fw[i][j]=='l')
    {
        refacere_drum(i-1,j-1);
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
            int ok;
            if(A[i]==B[j])
            {
                ok=1;
            }
            else
            {
                ok=0;
            }

            dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+ok));

            if(dp[i][j]==dp[i-1][j])
            {
                fw[i][j]='s';
            }
            else
            {
                if(dp[i][j]==dp[i][j-1])
                {
                    fw[i][j]='e';
                }
                else
                {
                    fw[i][j]='l';
                }
            }
        }
    }

    fout<< dp[M][N] << "\n";

    refacere_drum(M,N);

    return 0;
}
