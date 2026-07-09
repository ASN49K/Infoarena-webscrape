#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;

int n,m;

struct road
{
    int nod;
    int dist;
};

vector<road>v[N];
ll best[N];

priority_queue< pair<ll,int> >q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b,d;
        cin>>a>>b>>d;
        d*=2;
        v[a].push_back({b,d});
        v[b].push_back({a,d});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>best[i];
        q.push(-best[i],i);
    }
    while(!q.empty())
    {
        int nod=q.top().second;
        ll now=q.top().first;
        q.pop();
        if(now!=best[nod])
            continue;
        for(auto &it:v[nod])
        {
            int nou=it.nod;
            if(best[nod]+)
        }
    }
    return 0;
}
