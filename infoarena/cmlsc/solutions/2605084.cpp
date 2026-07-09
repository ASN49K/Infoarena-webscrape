#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short A[1025], B[1025], M, N, DP[1025][1025], subsir[1024], k=-1, i1, i2;

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
                DP[i][j]=1+DP[i-1][j-1];
            else
                DP[i][j]=(DP[i-1][j]>DP[i][j-1])?DP[i-1][j]:DP[i][j-1];
        }
    }

    i1=M;
    i2=N;
    while(i1>0 && i2>0)
    {
        if(A[i1]==B[i2])
        {
            subsir[++k]=A[i1];
            --i1;
            --i2;
        }
        else if(DP[i1-1][i2]>=DP[i1][i2-1])
            --i1;
        else
            --i2;
    }


    fout<<DP[M][N]<<'\n';
    for(short i=k;i>=0;i--)
        fout<<subsir[i]<<' ';
    return 0;
}
