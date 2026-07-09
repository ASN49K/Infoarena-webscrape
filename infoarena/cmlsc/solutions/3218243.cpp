#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1024], b[1024], d[1024][1024], sir[1024], bst;
int main(){
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    for(int i = m, j = n; i; )
        if(a[i] == b[j])
            sir[++bst] = a[i], i--, j--;
        else if(d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    fout << bst << '\n';
    for(int i = bst; i; i--)
        fout << sir[i] << ' ';
    return 0;
}
