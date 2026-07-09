#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int SCM[1025][1025];
int V[1025], W[1025];
int m, n;

void afis(int i, int j) {
    if(!i || !j) return;
    while(SCM[i][j] == SCM[i-1][j-1]) i--, j--;
    while(SCM[i][j] == SCM[i-1][j]) i--;
    while(SCM[i][j] == SCM[i][j-1]) j--;
    afis(i-1, j-1);
    if(i)
    fout<<V[i]<<" ";
}

int main() {
    fin>>m>>n;
    for(int i=1; i<=m; i++) {
        fin>>V[i];
        SCM[i][0] = -1;
    }
    for(int i=1; i<=n; i++) {
        fin>>W[i];
        SCM[0][i] = -1;
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(V[i] == W[j])
                SCM[i][j] = 1 + SCM[i-1][j-1];
            else
                SCM[i][j] = max(SCM[i-1][j], SCM[i][j-1]);
        }
    }

    fout<<SCM[m][n]+1<<'\n';
    int i=1, j=1;
    afis(m, n);

}
