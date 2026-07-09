#include <fstream>
using namespace std;
ifstream fin("LCS.in");
ofstream fout("LCS.out");
int LCS[1024][1024], A[1024], B[1024], P[1024];
int main(){
    int m, n, i, j, ct=0;
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
                ct++;
                P[ct]=A[i];
            }else{
                LCS[i][j]=max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
    }
    fout<<LCS[n][m]<<"\n";
    for(i=1;i<=ct;i++){
        fout<<P[i]<<" ";
    }
}
