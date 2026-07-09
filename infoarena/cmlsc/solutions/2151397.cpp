#include <fstream>
using namespace std;
ifstream input("cmlsc.in");
ofstream print("cmlsc.out");
int DP[1025][1025],LCS[1025];
int A[1025],B[1025];
int i,j,n,m,lg,mx;

void Read(){
    input>>n>>m;
    for(i=1;i<=n;i++)input>>A[i];
    for(i=1;i<=m;i++)input>>B[i];
}

void Rezolvare(){
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
           if(A[i-1]==B[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
           else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    }
    print<<DP[n][m]<<'\n';
    lg=DP[n][m];
    for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
            if(DP[i][j]==lg && A[i]==B[j]){
                    LCS[lg]=A[i];
                    lg--;
            }
    for(i=1;i<=DP[n][m];i++)print<<LCS[i]<<" ";
}

int main(){
    Read();
    Rezolvare();
    return 0;
}
