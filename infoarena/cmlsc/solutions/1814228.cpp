#include <fstream>

using namespace std;

int v[1025], w[1025], lcs[1025][1025], sol[1025], l;

int main()
{
    int n, m;
    ifstream fin ("cmlsc.in");
    fin >> n >> m;
    for(int i = 1; i <= n; ++i) fin >> v[i];
    for(int i = 1; i <= m; ++i) fin >> w[i];
    fin.close();
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(v[i] == w[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
    for(int i = n, j = m; i;)
            if(v[i] == w[j])
            {
                sol[++l] = v[i];
                i--; j--;
            }
            else if(lcs[i-1][j] < lcs[i][j-1]) j--;
            else i--;
    ofstream fout ("cmlsc.out");
    fout << l << '\n';
    for(int i = l; i; --i) fout << sol[i] << " ";
    fout.close();
    return 0;
}
