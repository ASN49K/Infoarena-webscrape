#include <cstdio>

#define nMax 1030
#define max(a,b) ((a>b)?a:b)

using namespace std;

int n;
int m;
char a[nMax];
char b[nMax];
char s[nMax][nMax];

void citire(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int j = 1; j <= m; ++ j){
        scanf("%d", &b[j]);
    }
}

void rezolvare(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(a[i] == b[j]){
                s[i][j] = 1 + s[i - 1][j - 1];
                continue;
            }
            s[i][j] = max(s[i - 1][j], s[i][j - 1]);
        }
    }
}

void afisare(int i, int j){
    if(s[i][j] == 0){
        return;
    }
    if(a[i] == b[j]){
        afisare(i - 1, j - 1);
        printf("%d ", a[i]);
        return;
    }
    if(s[i - 1][j] > s[i][j - 1]){
        afisare(i - 1, j);
    }else{
        afisare(i, j - 1);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    rezolvare();
    printf("%d\n", s[n][m]);
    afisare(n, m);

    return 0;
}
