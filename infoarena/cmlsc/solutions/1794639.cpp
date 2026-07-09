#include <cstdio>
#include <vector>
#define NMAX 1030
using namespace std;

FILE* fin = fopen("cmlsc.in","r");
FILE* fout = fopen("cmlsc.out","w");

int a[NMAX],b[NMAX];
int dp[NMAX][NMAX];
int last[NMAX][NMAX];
vector<int> sol;

int M,N;
int main()
{
    fscanf(fin,"%d %d",&M,&N);
    for(int i = 1; i <= M; i++)
        fscanf(fin,"%d",&a[i]);
    for(int i = 1; i <= N; i++)
        fscanf(fin,"%d",&b[i]);

    for(int i = 1; i <= M;i++)
        for(int j = 1; j <= N; j++)
        {
            if(a[i] == b[j])
            {
                if(dp[i][j] < dp[i-1][j-1]+1)
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    last[i][j] = (i-1)*NMAX+j-1;
                }
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                {

                    dp[i][j] = dp[i][j-1];
                    last[i][j] = i*NMAX+j-1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    last[i][j] = (i-1)*NMAX+j;
                }
            }
        }
    fprintf(fout,"%d\n",dp[M][N]);
    while(dp[M][N])
    {
        if(a[M] == b[N])
            sol.push_back(a[M]);
        int i = last[M][N]/NMAX;
        int j = last[M][N]%NMAX;
        M=i, N=j;
    }
    for(int i = sol.size()-1; i>=0;i--)
        fprintf(fout,"%d ",sol[i]);
    fprintf(fout,"\n");
    return 0;
}
