#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1025], b[1025], d[1025][1025], v[1025], dim;

int main()
{
    fin >> n >> m;

    for(int i=1; i<=n; i++)
        fin >> a[i];

    for(int i=1; i<=m; i++)
        fin >> b[i];

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    }

    dim = 0;

    int i=n, j=m;
    while(i>0 && j>0) {
        if(a[i] == b[j]) {
            v[++dim] = a[i];
            i--;
            j--;
        }
        else {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    }

    fout << dim << '\n';
    for(int i=1; i<=dim; i++)
        fout << v[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
