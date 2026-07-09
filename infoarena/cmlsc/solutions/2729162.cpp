#include <fstream>
using namespace std;
ifstream fin("LCS.in");
ofstream fout("LCS.out");
int LCS[1028][1028], A[1028], B[1028];
int main(){
    int m, n, i, j, ct=0, ct2;
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>A[i];
    }
    for(i=1;i<=m;i++){
        fin>>B[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(A[i]==B[j]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }else{
                LCS[i][j]=max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
    }
    ct = LCS[n][m];
    ct2=ct;
    int P[ct+1];
    i=n;j=m;
    while(i>=1&&j>=1){
        if(A[i]==B[j]){
            P[ct--]=A[i];
            i--;j--;
        }else {
            if(LCS[i-1][j]>LCS[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    fout<<LCS[n][m]<<"\n";
    for(i=1;i<=ct2;i++){
        fout<<P[i]<<" ";
    }
}
