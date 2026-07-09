#include <fstream>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int A[1500],B[1500],DP[1500][1500],rs[1500],k=0,m,n;

int main(){
    cin>>m>>n;
    for (int i=1; i<=m; i++) cin>>A[i];
    for (int j=1; j<=n; j++) cin>>B[j];
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    int i=m;
    int j=n;
    while (i>0 && j>0){
        if (A[i]==B[j]){
            rs[++k]=A[i];
            i--;
            j--;
        }
        else
            if(DP[i-1][j]>DP[i][j-1]) i--;
             else j--;
    }
    cout<<DP[m][n]<<"\n";
    for (int p=k; p>=1; p--){
            cout<<rs[p]<<" ";
    }
    return 0;
}
