#include <stdio.h>
#include <stdlib.h>

int a[1030][1030];
int n,m;
int s1[1030], s2[1030];

void afisare(int x, int y){
    if(!(1<=x && x<=n && 1<=y && y<=m))
        return;
    if(s1[x] == s2[y]){
        afisare(x-1,y-1);
        printf("%d ", s1[x]);
    }else{
        if(a[x-1][y] > a[x][y-1])
            afisare(x-1,y);
        else
            afisare(x,y-1);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &s1[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &s2[i]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s1[i] == s2[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = (a[i-1][j] > a[i][j-1]) ? a[i-1][j] : a[i][j-1];

    printf("%d\n", a[n][m]);
    afisare(n,m);
    return 0;
}
