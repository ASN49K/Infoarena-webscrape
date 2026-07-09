#include<stdio.h>
#include<vector>
#include<algorithm>

#define NMAX 1027

using namespace std;

int n, m, D[NMAX][NMAX], a[NMAX], b[NMAX];
vector<int> sol;

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++ i)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++ i)/// D[i][j] - cel mai lung subsir comun pana la elem i din A si pana la elem j din B
        for(int j = 1; j <= m; ++ j)
            if(a[i] == b[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
    printf("%d\n", D[n][m]);
    for(int i = n, j = m; D[i][j] > 0;)
        if(a[i] == b[j]){
            sol.push_back(a[i]);
            -- i;
            -- j;
        }
        else
            if(D[i - 1][j] > D[i][j - 1])
                -- i;
            else
                -- j;
    for(int i = sol.size() - 1; i >= 0; -- i)
        printf("%d ", sol[i]);
    return 0;
}
