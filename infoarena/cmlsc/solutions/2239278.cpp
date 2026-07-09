#include <fstream>
#include <stack>

using namespace std;

stack<int> sol;

int n, m, a[1025], b[1025], mat[1025][1025];

void solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == a[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    int i = n, j = m;
    while (i > 0 && j > 0)
        if (a[i] == b[j])
        {
            sol.push(a[i]);
            --i;
            --j;
        }
        else if (mat[i][j-1] > mat[i-1][j])
            --j;
        else --i;
    
    ofstream fout("cmlsc.out");
    fout << mat[n][m] << '\n';
    for (; !sol.empty(); sol.pop())
        fout << sol.top() << " ";
    fout.close();
}

int main() {
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
    fin.close();
    
    return 0;
}
