#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short A[1025], B[1025], M, N, DP[1025][1025], subsir[1024], k=-1;

int main()
{
    fin>>M>>N;
    for(short i=1;i<=M;i++)
        fin>>A[i];
    for(short j=1;j<=N;j++)
        fin>>B[j];

    for(short i=1;i<=M;i++)
    {
        for(short j=1;j<=N;j++)
        {
            if(A[i]==B[j])
            {
                DP[i][j]=1+DP[i-1][j-1];
                subsir[++k]=A[i];
            }
            else
                DP[i][j]=(DP[i-1][j]>DP[i][j-1])?DP[i-1][j]:DP[i][j-1];
        }
    }

    fout<<DP[M][N]<<'\n';
    for(short i=0;i<=k;i++)
        fout<<subsir[i]<<' ';
    return 0;
}
