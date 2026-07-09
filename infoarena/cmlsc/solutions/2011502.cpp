#include <bits/stdc++.h>

using namespace std;

ifstream F("cmlsc.in");
ofstream G("cmlsc.out");

int n, m, v[1030], w[1030], l[1030][1030], x, y;
stack<int> st;

int main()
{
    F >> n >> m;
    for(int i = 1; i <= n; ++ i) F >> v[i];
    for(int i = 1; i <= m; ++ i) F >> w[i];
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(v[i] == w[j]) l[i][j] = l[i-1][j-1]+1;
            else l[i][j] = max(l[i-1][j], l[i][j-1]);
    G << l[n][m] << '\n';
    int x = n; y = m;
    while(l[x][y])
    {
        if(l[x][y] == l[x-1][y]) x--;
        else if(l[x][y] == l[x][y-1]) y--;
        else st.push(v[x]), x--, y--;
    }
    while(!st.empty()) G << st.top() << " ", st.pop();
    return 0;
}
