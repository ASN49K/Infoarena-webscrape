#include <bits/stdc++.h>

using namespace std;
ifstream fin ("minperm.in");
ofstream fout ("minperm.out");

int n, k;

int main()
{
    fin >> n >> k;
    vector <int> pos(n+1), l(k+1);
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        fin >> x;
        pos[x] = i;
    }
    for(int i = 1 ; i <= k ; i++)
        fin >> l[i];
    vector<int> sol(n+1);
    vector<bool> used(n+1);

    for(int i = 1; i <= n ; i++)
    {
        queue<int> q;
        q.push(pos[i]);
        vector<bool> vis(n+1);
        vis[pos[i]] = true;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int j = 1 ; j <= k ; j++)
            {
                if(u - l[j] > 0 && !vis[u - l[j]])
                {
                    q.push(u - l[j]);
                    vis[u - l[j]] = true;
                }
                if(u + l[j] <= n && !vis[u + l[j]])
                {
                    q.push(u + l[j]);
                    vis[u + l[j]] = true;
                }
            }
        }
        for(int p = 1 ; p <= n ; p++)
        {
            if(vis[p] && !used[p])
            {
                sol[p] = i;
                used[p] = true;
                break;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
        fout << sol[i] << " ";
    return 0;
}
