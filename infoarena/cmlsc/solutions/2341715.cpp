#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAX_SIZE = 1025;

int A[MAX_SIZE], B[MAX_SIZE], print[MAX_SIZE];
short int dp[MAX_SIZE][MAX_SIZE];

int buildDP(int n, int m){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    return dp[n][m];
}

void buildPrint(int n, int m, int &size){
    int x = n;
    int y = m;
    size = 0;

    while(x > 0 && y > 0)
        if(A[x] == B[y]){
            print[++size] = A[x];
            x--;
            y--;
        }
        else if(dp[x-1][y] < dp[x][y-1])
            y--;
        else
            x--;

}

int main()
{
    int n, m, size;

    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>A[i];
    for(int i=1;i<=m;i++)
        in>>B[i];
    in.close();

    out<<buildDP(n,m)<<"\n";
    buildPrint(n,m,size);
    for(int i=size;i>=1;i--)
        out<<print[i]<<" ";
    out<<"\n";
    out.close();

    return 0;
}
