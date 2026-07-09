#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 1027;

int D[NMAX][NMAX], n, m, a[NMAX], b[NMAX];
vector< int > Sol;

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int j = 1; j <= m; ++j)
        scanf("%d", &b[j]);
    /// Dinamica
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i][j - 1], D[i - 1][j]);
    printf("%d\n", D[n][m]);
    /// Reconstituire
    for(int i = n, j = m; D[i][j] > 0;)
        if(a[i] == b[j]){
            Sol.push_back(a[i]);
            --i;
            --j;
        }
        else
            if(D[i - 1][j] > D[i][j - 1])
                --i;
            else
                --j;
    reverse(Sol.begin(), Sol.end());
    for(vector< int >::iterator it = Sol.begin(); it != Sol.end(); ++it)
        printf("%d ", *it);
    return 0;
}
