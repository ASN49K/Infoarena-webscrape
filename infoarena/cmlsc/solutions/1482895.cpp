#include <fstream>
#include <vector>
using namespace std;

inline int maxx(const int a, const int b){
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n;
    int m;
    f >> n;
    f >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) f >> a[i];
    
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) f >> b[i];
    
    vector<vector<int> > d(n + 1, vector<int>(m + 1, 0));
    vector<int> sir(n + m + 2);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = maxx(d[i - 1][j], d[i][j - 1]);
    
    int i, j, index;
    for (i = n, j = m; i;)
        if (a[i] == b[j]){
            sir[++index] = a[i];
            i--;
            j--;
        }
        else if (d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    
    g << index << '\n';
    for (i = index; i; i--)
        g << sir[i] << ' ';
    
    f.close();
    g.close();
    return 0;
}
