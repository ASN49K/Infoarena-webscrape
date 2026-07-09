#include <iostream>
#include <fstream>

#define maxim(a,b) ((a > b) ? a : b)
#define NMAX 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int N,M,A[NMAX],B[NMAX],C[NMAX],sol[NMAX][NMAX],max=0;
    f>>N>>M;
    for(int i = 1; i <= N ; ++i)
    {
        f>>A[i];
    }
    for(int i = 1; i <= N ; ++i)
    {
        f>>B[i];
    }
    for(int i = 1; i <= N ; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(A[i]==B[i])
                sol[i][j]=1+sol[i-1][j-1];
            else
                sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
        }
    }
    for (int i = M, j = N; i; )
    {
        if (A[i] == B[j])
            C[++max] = A[i], --i, --j;
        else if (sol[i-1][j] < sol[i][j-1])
            --j;
        else
            --i;
    }
    g<<max<<endl;
    for (int i = max; i; --i)
        g<<C[i]<<endl;

    return 0;
}
