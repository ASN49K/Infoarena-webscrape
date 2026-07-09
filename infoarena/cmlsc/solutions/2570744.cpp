#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,j,a[1025],b[1025],mat[1025][1025];
stack <int> stk;

int main()
{
    f >> n >> m;
    for(i = 1; i <= n; ++ i)
        f >> a[i];
    for(j = 1; j <= m; ++ j)
        f >> b[j];
    for(i = 1; i <= n; ++ i)
        for(j = 1; j <= m; ++ j)
            if(a[i] == b[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
    i = n;
    j = m;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            stk.push(a[i]);
            -- i;
            -- j;
        }
        else if(mat[i - 1][j] > mat[i][j - 1])
            -- i;
        else
            -- j;
    }
    g << stk.size() << '\n';
    while(!stk.empty())
    {
        g << stk.top() << ' ';
        stk.pop();
    }
}
