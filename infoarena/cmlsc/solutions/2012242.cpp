#include <bits/stdc++.h>

using namespace std;

FILE *F=fopen("cmlsc.in", "r"), *G=fopen("cmlsc.out", "w");

int n, m, v[1030], w[1030], x, y, a[1030][1030];
stack<int> st;

int main()
{
    fscanf(F, "%d %d ", &n, &m);
    for(int i = 1; i <= n; ++ i) fscanf(F, "%d ", &v[i]);
    for(int i = 1; i <= m; ++ i) fscanf(F, "%d ", &w[i]);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(v[i] == w[j]) a[i][j] = a[i-1][j-1] + 1;
            else a[i][j] = max(a[i-1][j], a[i][j-1]);
        }
    fprintf(G, "%d\n", a[n][m]);
    x = n; y = m;
    while(x && y)
    {
        if(a[x][y] == a[x-1][y]) x--;
        else if(a[x][y] == a[x][y-1]) y--;
        else st.push(v[x]), x--, y--;
    }
    while(!st.empty())
        fprintf(G, "%d ", st.top()), st.pop();
    return 0;
}
