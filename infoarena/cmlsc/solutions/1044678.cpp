#include <cstdio>
#include <stack>


int main()
{
    int m, n;
    int a[1100], b[1100];
    int **d;
    std::stack<int> s;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    d = new int*[m+1];
    d[0]=new int[n+1]();
    for (int i=1; i<=m; ++i){
        scanf("%d", &a[i]);
        d[i]=new int[n+1]();
    }
    for (int i=1; i<=n; ++i){
        scanf("%d", &b[i]);
    }

    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j){
            if (a[i]==b[j]){
                d[i][j] = d[i-1][j-1]+1;
            }
            else{
                d[i][j] = d[i-1][j]>d[i][j-1] ? d[i-1][j] : d[i][j-1];
            }
        }

    printf("%d\n", d[m][n]);
    int i=m, j=n;

    while (d[i][j]){
        if (a[i]==b[j]){
            s.push(a[i]);
            --i;
            --j;
        }
        else{
            if (d[i][j-1]>d[i-1][j]){
                --j;
            }
            else{
                --i;
            }
        }
    }
    while (!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}
