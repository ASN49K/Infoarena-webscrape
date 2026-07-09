#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,A[1025],B[1025],DP[1025][1025],cnt,V[1001];

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
    int i = n, j = m;
    while(i>0 && j>0){
            if(A[i] == B[j]){
                V[++cnt] = A[i];
                i--;
                j--;
            }
            else if(DP[i-1][j]==DP[i][j]) i--;
            else j--;
        }
        for(int i=cnt;i>=1;i--) fout << V[i] << ' ';
        return 0;
}
