#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,A[2001],B[2001],DP[201][201],cnt,V[2001];

int main(){
    fin >> n >> m;
    for(int i=1;i<=n;i++) fin >> A[i];
    for(int j=1;j<=m;j++) fin >> B[j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(A[i] != B[j]){
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
            else DP[i][j] = 1 + DP[i-1][j-1];
        }
    fout << DP[n][m] << '\n';

    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--){
            if(A[i] == B[j]){
                V[++cnt] = A[i];
                i--;
                j--;
            }
            else if(DP[i-1][j]==DP[i][j]) i--;
        }
        for(int i=cnt;i>=1;i--) fout << V[i] << ' ';
}
