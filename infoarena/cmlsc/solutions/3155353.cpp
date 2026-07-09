#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int d[1026][1026], n, m, a[1025], b[1025], sub[1025],len=0;
int main()
{
    fin >> m >> n;
    for (int i=1; i<=m; ++i) {
        fin>>a[i];
    }
    for (int i=1; i<=n; ++i) {
        fin>>b[i];
    }
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
            }
            else {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    for (int i=m; i>=1; i) {
        for (int j=n; j>=1; j) {
            if (a[i]==b[j]) {
                sub[++len]=a[i];
                i--;
                j--;
            }
            else if (d[i-1][j]<d[i][j-1]) {
                j--;
            }
            else {
                i--;
            }
        }
    }
    fout << d[m][n] <<'\n';
    for (int i=len; i>=1; --i) {
        fout << sub[i] << ' ';
    }
    return 0;
}
