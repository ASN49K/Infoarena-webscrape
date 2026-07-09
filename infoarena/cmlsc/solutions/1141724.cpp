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
    vector< vector<short> > dir;

    int M, N;

    fin>>M>>N;

    A.resize(M);
    B.resize(N);
    LCS.resize(M+1);
    dir.resize(M);
    for(short i=0; i<=M; i++)
    {
        LCS[i].assign(N+1, 0);

        if(i<M)
            dir[i].resize(N);
    }

    for(int i=0; i<M; i++)
        fin>>A[i];
    for(int i=0; i<N; i++)
        fin>>B[i];

    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            if(A[i-1]==B[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
                dir[i-1][j-1]=2; /** good direction */
            }
            else
            {
                LCS[i][j]=max(LCS[i][j-1], LCS[i-1][j]);
                if(LCS[i][j]==LCS[i][j-1])
                    dir[i-1][j-1]=3;
                else
                    dir[i-1][j-1]=1;
            }

    fout<<LCS[M][N]<<'\n';

    short i=M-1, j=N-1;
    vector<bool> test(N, false);

    while(i>=0 && j>=0)
        switch (dir[i][j])
        {
            case 1: i--; break;
            case 2: test[j]=true; i--; j--; break;
            case 3: j--; break;
        }

    for(short i=0; i<N; i++)
        if(test[i]==true)
            fout<<B[i]<<' ';

    return 0;
}
