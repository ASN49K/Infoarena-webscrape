///LCS
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    vector< vector<int> > LCS;
    vector<int> A;
    vector<int> B;

    int M, N;

    fin>>M>>N;
    A.resize(M);
    B.resize(N);
    LCS.resize(M+1);
    for(short i=0; i<=M; i++)
        LCS[i].assign(N+1, 0);
    for(int i=0; i<M; i++)
        fin>>A[i];
    for(int i=0; i<N; i++)
        fin>>B[i];

    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            if(A[i-1]==B[j-1])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i][j-1], LCS[i-1][j]);

    for(short i=1; i<=M; i++)
    {
        for(short j=1; j<=N; j++)
            cout<<LCS[i][j]<<' ';
        cout<<'\n';
    }

    fout<<LCS[M][N]<<'\n';

    int last=0;
    for(int i=1; i<=N; i++)
        if(LCS[M][i]==last+1)
        {
            fout<<B[i-1]<<' ';
            last=LCS[M][i];
        }

    return 0;
}
