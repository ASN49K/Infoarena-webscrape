#include <fstream>
using namespace std;
ifstream input("cmlsc.in");
ofstream print("cmlsc.out");
int DP[1025][1025],LCS[1025];
int A[1025],B[1025];
int i,j,n,m,lg,mx;

void Read(){
    input>>n>>m;
    for(i=0;i<n;i++)input>>A[i];
    for(i=0;i<m;i++)input>>B[i];
}

void Rezolvare(){
    for(i=0;i<=n;i++)
    for(j=0;j<=m;j++){
            if(i==0||j==0)
                DP[i][j]=0;
         else if(A[i-1]==B[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
         else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    }
    print<<DP[n][m]<<'\n';
    lg=DP[n][m];
    i=n,j=m;
    while(i>0 && j>0){
            if(A[i-1]==B[j-1]){
            LCS[lg--]=A[i-1];
            i--,j--;
            }
        else if(DP[i-1]>DP[j-1])
            i--;
        else j--;
    }
    for(i=1;i<=DP[n][m];i++)print<<LCS[i]<<" ";
}

int main(){
    Read();
    Rezolvare();
    return 0;
}
