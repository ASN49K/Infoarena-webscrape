#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

ifstream F("cmlsc.in");
ofstream G("cmlsc.out");

int n, m, w[1050], v[1050], a[1050][1050], x, y;
stack<int> st;

int main()
{
    F >> n >> m;
    for(int i = 1; i <= n; ++ i) F >> v[i];
    for(int i = 1; i <= m; ++ i) F >> w[i];
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(v[i]==w[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i][j-1], a[i-1][j]);
    G << a[n][m] << '\n';
    x=n; y=m;
    while(a[x][y])
    {
        if(a[x][y]==a[x-1][y]) x--;
        else if(a[x][y]==a[x][y-1]) y--;
        else {st.push(v[x]); x--, y--;}
    }
    while(!st.empty()) G << st.top()<< " ", st.pop();
    return 0;
}
