#include <fstream>
using namespace std;
int n, m, i, j, sol[1025], k;
int tata[1025][1025], d[1025][1025], a[1025], b[1025];

int main () {
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (i=1;i<=n;i++) {
        fin>>a[i];
    }
    for (i=1;i<=m;i++)
        fin>>b[i];

    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
                tata[i][j]=1;
            } else if (a[i]!=b[j]) {
                d[i][j]=max(d[i-1][j], d[i][j-1]);
                if (d[i][j]==d[i][j-1])
                    tata[i][j]=3;
                else if (d[i][j]==d[i-1][j])
                    tata[i][j]=2;
            }
        }
    }

    fout<<d[n][m]<<"\n";
    i=n;j=m;
    while (d[i][j]!=0) {
        if (tata[i][j]==1) {
            sol[++k]=a[i];
            i--; j--;
        } else if (tata[i][j]==2) {
            i--;
        } else if (tata[i][j]==3) {
            j--;
        }
    }
    for (i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
