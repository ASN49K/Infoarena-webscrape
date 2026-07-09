#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int SCM[1025][1025];
int V[1025], W[1025];
int m, n;

int main() {
    fin>>m>>n;
    for(int i=1; i<=m; i++) {
        fin>>V[i];
    }
    for(int i=1; i<=n; i++) {
        fin>>W[i];
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(V[i] == W[j])
                SCM[i][j] = 1 + SCM[i-1][j-1];
            else
                SCM[i][j] = max(SCM[i-1][j], SCM[i][j-1]);
        }
    }

    fout<<SCM[m][n]<<'\n';
    for(int i=1; i<=m; i++) {
        if(SCM[i][n] > SCM[i-1][n])
            fout<<V[i]<<" ";
    }

}
