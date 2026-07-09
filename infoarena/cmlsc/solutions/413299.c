#include <stdio.h>
#define MAX 1024
int s[MAX + 1][MAX + 1], path[MAX + 1][MAX + 1];

int mx(int a, int b, int c){
    int m = (a > b) ? a:b;
    m = (m > c) ? m:c;
    if(m == b) return 2;
    if(m == a) return 1;
    if(m == c) return 3;
}

int main(int argc, char** argv){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i,j, n,m, v1[MAX], v2[MAX], k, l, sub[MAX], p;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) scanf("%d", &v1[i]);
    for(i = 0; i < m; i++) scanf("%d", &v2[i]);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            if(v1[i - 1] == v2[j - 1]) s[i][j] = 1;
            k = mx(s[i][j - 1], s[i - 1][j - 1], s[i - 1][j]);
            if(k == 1 && s[i][j - 1] > s[i][j]){
                path[i][j] = 1;
                s[i][j] += s[i][j - 1];
                continue;
            }
            if(k == 2){
                path[i][j] = 2;
                s[i][j] += s[i - 1][j - 1];
                continue;
            }
            if(k == 3 && s[i - 1][j] > s[i][j]){
                path[i][j] = 3;
                s[i][j] += s[i - 1][j];
                continue;
            }
            path[i][j] = 0;
        }
    l = s[n][m];
    k = l - 1;
    p = path[n][m];
    i = n; j = m;
    while(p){
        if(v1[i - 1] == v2[j - 1]) {
            sub[k] = v1[i - 1];
            k--;
        }
        p = path[i][j];
        if(p == 1) j--;
        if(p == 3) i--;
        if(p == 2){ i--; j--; }
    }
    printf("%d\n", l);
    for(i = 0; i < l; i++)
        printf("%d ", sub[i]);


    return 0;
}
