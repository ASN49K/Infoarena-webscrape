#include <bits/stdc++.h>

using namespace std;


int main () 
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> g;
    vector<int> numere;
    for(int i=1; i<=n; i++)
    {
        int v;
        cin>>v;
        g[v].push_back(i);
    }
    for(int i=1; i<=m; i++)
    {
        int v;
        cin>>v;
        if(g.count(v))
        {
            numere.push_back(v);
        }
    }
    cout<<numere.size()<<'\n';
    for(auto ti: numere)
    {
        cout<<ti<<" ";
    }
}