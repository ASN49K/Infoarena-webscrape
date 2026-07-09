#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int NMAX = 1024+5;
const int MMAX = 1024+5;

void Read(),Solve(),Print();

int N,M;
int A[NMAX];
int B[MMAX];
int DP[NMAX][MMAX];
vector<int> Sol;

int main()
{
    Read();
    Solve();
    Print();

    return 0;
}

void Read()
{
    int i;

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&N,&M);

    for(i = 1; i <= N; i++)
        scanf("%d",&A[i]);

    for(i = 1; i <= M; i++)
        scanf("%d",&B[i]);
}

void Solve()
{
    int i,j;

    for(i = 1; i <= N; i++)
        for(j = 1; j <= M; j++)
            if(A[i] == B[j]) DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);

    for(i = N, j = M; i && j; )
        if(A[i] == B[j]) Sol.push_back(A[i]),i--,j--;
        else if(DP[i-1][j] > DP[i][j-1]) i--;
        else j--;
}

void Print()
{
    int i;

    printf("%d\n",DP[N][M]);

    for(i = DP[N][M] - 1; i >= 0; i--)
        printf("%d ",Sol[i]);
}
