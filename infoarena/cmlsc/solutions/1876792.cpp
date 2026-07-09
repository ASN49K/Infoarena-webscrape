#include <fstream>
#include<vector>
#define NMAX 1024
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[NMAX],B[NMAX],LCS[NMAX][NMAX];
int N,M;
vector<int> sol;
//LCS[i][j] = cel mai lung subsir comun format din prefixul Ai si Bj
int main()
{
    fin>>N>>M;
    FOR(i,1,N)
        fin>>A[i];
    FOR(i,1,M)
        fin>>B[i];
    FOR(i,1,N)
        FOR(j,1,N)
            if(A[i] == B[j])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
            }
    fout<<LCS[N][M]<<'\n';

    while(LCS[N][M])
    {
        if(A[N] == B[M])
        {
            sol.push_back(A[N]);
            N--;
            M--;
        }
        else if(LCS[N-1][M]< LCS[N][M-1])
            M--;
        else N--;
    }
    for(int i = sol.size()-1;i>=0;i--)
        fout<<sol[i]<<" ";
    fout<<'\n';
    return 0;
}
