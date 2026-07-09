#include <fstream>

using namespace std;

const int MAX = 1024;

int v1[MAX],v2[MAX],D[MAX][MAX],r[MAX];

int main() {
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n,m,l,i,j,k;
    fin>>n>>m;
    for (i=1;i<=n;i++) {
        fin>>v1[i];
    }
    for (j=1;j<=m;j++) {
        fin>>v2[j];
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (v1[i]==v2[j]) {
                D[i][j]=D[i-1][j-1]+1;
            }
            else {
                D[i][j]=max(D[i-1][j], D[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    k=0;
    while (i > 0 && j > 0) {
        if (v1[i]==v2[j]) {
            r[k++]=v1[i];
            --i;
            --j;
        }
        else if (D[i-1][j]>=D[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }
    fout<<k<<endl;
    for (l=k-1;l>=0;l--) {
        fout<<r[l]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
