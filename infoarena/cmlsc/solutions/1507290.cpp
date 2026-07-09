# include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025], B[1025],D[1025][1025],S[1025],n,m,i,j,k;
int main () {
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>A[i];
    }
    for(i=1;i<=m;i++){
        fin>>B[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(A[i]==B[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
    }
    fout<<D[n][m]<<"\n";

    i = n;
    j = m;
    while (k!=D[n][m]) {
        if (A[i] == B[j]) {
            S[++k] = A[i];
            i--;
            j--;
        } else
            if (D[i-1][j] > D[i][j-1])
                i--;
            else
                j--;
    }
    for (i=k;i>=1;i--){
        fout<<S[i]<<" ";
    }
    return 0;
}
