#include <cstdio>
#include <vector>
#define NMAX 1030
using namespace std;

#define maxim(a,b) ((a > b) ? a : b)
#define FOR(i, a, b) for(int i = a; i <= b; ++i)

FILE* fin = fopen("cmlsc.in","r");
FILE* fout = fopen("cmlsc.out","w");

int a[NMAX],b[NMAX], dp[NMAX][NMAX];
vector<int> sol;

int M,N;
int main()
{
    fscanf(fin,"%d %d",&M,&N);
    FOR(i,1,M)
        fscanf(fin,"%d",&a[i]);
    FOR(i,1,N)
        fscanf(fin,"%d",&b[i]);

    FOR(i,1,M)
        FOR(j,1,N)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = maxim(dp[i][j-1], dp[i-1][j]);
            }
        }

    fprintf(fout,"%d\n",dp[M][N]);
    while(dp[M][N])
    {
        if(a[M] == b[N])
        {
            sol.push_back(a[M]);
            M--;
            N--;
        }
        else if(dp[M-1][N] < dp[M][N-1])
            N--;
        else
            M--;
    }

    for(int i = sol.size()-1; i>=0;i--)
        fprintf(fout,"%d ",sol[i]);
    fprintf(fout,"\n");
    return 0;
}
