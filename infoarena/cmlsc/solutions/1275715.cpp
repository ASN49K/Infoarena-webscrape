#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define Nmax 1026
using namespace std;

int mat[Nmax][Nmax], N, M, A[Nmax], B[Nmax], sol[Nmax];

int main()
{
    ifstream f("cmlsc.in");
    f>>N>>M;
    for(int i=1;i<=N;++i)
        f>>A[i];

    for(int i=1;i<=M;++i)
        f>>B[i];

    f.close();

    for(int i=0; i<=N;++i)
        for(int j=0;j<=M;++j)
            mat[i][j] = 0;

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
        {
            if(A[i] == B[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }

    ofstream g("cmlsc.out");
    g<<mat[N][M]<<"\n";
    int i, j, var,last_i, last_j;

    for(var=mat[N][M], last_i = N, last_j = M; var > 0; --var)
    {
        for(i = last_i; i > 0; --i)
            for(j = last_j; j > 0 && mat[i][j] == var; --j)
            {
                if(A[i] == B[j])
                {
                    sol[var] = A[i];
                    last_i = i-1;
                    last_j = j-1;
                    i=j=-1;
                }
            }
    }

    for(int i=1;i<=mat[N][M];++i)
        g<<sol[i]<<" ";
    g.close();
    return 0;
}
