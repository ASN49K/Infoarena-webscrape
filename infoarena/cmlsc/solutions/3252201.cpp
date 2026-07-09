#include <bits/stdc++.h>

using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int NMAX = 100000;

int n, maxi;
int v[NMAX+1];
int dp[NMAX+1], pos[NMAX+1],  p = 1;

int main()
{
    fin >> n;
    for(int i=1; i<=n; i++)
        fin >> v[i];
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(v[i] > v[j])
                if(dp[j]+1 > dp[i])
                    dp[i] = dp[j]+1, pos[i] = j;
        }
        if(dp[i] > maxi)
            maxi = dp[i], p = i;
    }  
    vector <int> ans;
    while(p)
    {
        ans.push_back(v[p]);
        p  = pos[p];
    } 
    fout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(int x : ans)
        fout << x << ' ';
    return 0;
}