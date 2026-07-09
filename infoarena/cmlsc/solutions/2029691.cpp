#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

ifstream F("cmlsc.in");
ofstream G("cmlsc.out");

int n, m, k, sol, w[1050], v[1050], stsol[1050];
pair<int, int> st[1050];

int main()
{
    F >> n >> m;
    for(int i = 1; i <= n; ++ i) F >> v[i];
    for(int i = 1; i <= m; ++ i) F >> w[i];
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= m; ++ j)
            if(w[j]==v[i])
            {
                if(!k)
                {
                    st[++k]={w[j], j};
                    continue;
                }
                while(k)
                {
                    if(st[k].s > j) k--;
                    else {st[++k]={w[j], j};break;}
                }
                break;
            }
        if(k>sol)
        {
            sol = k;
            for(int j = 1; j <= k; ++ j) stsol[j]=st[j].s;
        }
    }
    G << sol << '\n';
    for(int i = 1; i <= sol; ++ i)
        G << w[stsol[i]] << " ";
    return 0;
}
