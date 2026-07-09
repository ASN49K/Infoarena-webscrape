#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1025],b[1025],d[1025][1025],sir[1025];

int main() {
    f>>m>>n;
    for(int i=1; i<=m; i++) f>>a[i];
    for(int i=1; i<=n; i++) f>>b[i];

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);

    int maxim=1;
    int i=m, j=n;
    while(i) {
        if(a[i]==b[j]) {
            sir[maxim++]=a[i];
            i--;
            j--;
        } else if(d[i-1][j] < d[i][j-1]) j--;
        else i--;
    }

    g<<maxim-1<<'\n';
    for(int i=maxim-1; i>=1; i--) g<<sir[i]<<" ";
    return 0;
}
