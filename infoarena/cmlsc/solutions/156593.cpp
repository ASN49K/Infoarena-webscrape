#include <fstream>
#define MAX 1025
#define maxi(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int m, n, a[MAX], b[MAX], d[MAX][MAX];

int main()
{
    int i, j, l = 0, rez[MAX];
    
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (i = 1; i <= n; i++)    
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
            else              d[i][j] = maxi(d[i-1][j], d[i][j-1]);
    
    for (i = n, j = m; i > 0 && j > 0; )
        if (a[i] == b[j]) { rez[++l] = a[i]; i--; j--; }
        else  if (d[i][j] == d[i-1][j]) i--;
              else                      j--;
    
    ofstream fout("cmlsc.out");
    fout << l << "\n";
    for (i = l; i >= 1; i--)
        fout << rez[i] << " ";
    fout.close();
    
    return 0;
}
