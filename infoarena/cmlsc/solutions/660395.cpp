#include<stdio.h>
int d[1025][1025], p, v[1025], u[1025], sol[1025];
int reface (int n, int m){
    if(d[n][m]!=0){
        if(v[n]==u[m]){
            sol[p--]=v[n];
            reface(n-1, m-1);
        }
        else
            if(d[n][m]==d[n-1][m])
                reface(n-1, m);
            else
                reface(n, m-1);
    }
}
int main(){
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    int n, m, i, j;
    scanf("%d %d ", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%d ", &v[i]);
    for(j=1; j<=m; j++)
        scanf("%d ", &u[j]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(v[i]==u[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                if(d[i-1][j]>=d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];

    printf("%d\n", d[n][m]);
    p=d[n][m];
    reface(n, m);
    for(i=1; i<=d[n][m]; i++)
        printf("%d ", sol[i]);

    return 0;
}
