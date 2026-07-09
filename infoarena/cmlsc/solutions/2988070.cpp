#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1025],B[1025],dp[1025][1025];

void drum(int i,int j) {
    if(i==0 || j==0) return;
    if(A[i] == B[j]) {
        drum(i-1,j-1);
        fout<<A[i]<<" ";
    }
    else {
        if(dp[i][j] == dp[i][j-1]) drum(i,j-1);
        else {
            drum(i-1,j);
        }
    }
}
int main()
{
    int i,j,n,m;
    fin>>n>>m;
    for(i=1;i<=n;i++) {
        fin>>A[i];
    }
    for(j=1;j<=m;j++) {
        fin>>B[j];
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(A[i]==B[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    fout<<dp[n][m]<<"\n";
    drum(n,m);
}
