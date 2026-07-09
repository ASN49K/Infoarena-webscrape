#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025];
int com[1025][1025];

int main() {
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++) {
        fin>>a[i];
    }
    for (int i=1;i<=m;i++) {
        fin>>b[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                com[i][j]=1+com[i-1][j-1];
            }else {
                com[i][j]=max(com[i][j-1],com[i-1][j]);
            }
        }
    }
    fout<<com[n][m]<<"\n0";
    return 0;
}