#include <bits/stdc++.h>

using namespace std;
ifstream f("paths.in");
ofstream g("paths.out");
struct nod
{
    int G,T,S;///grad,tata,fiul
    int64_t DL;///distanta pana la frunza

};
/// down = spre frunze
/// up = spre radacina
const int N = 100010;
int n,k,p,gr[N],gc[N],T[N],S[N],CS[N],CT[N],L[N],sol[N],solA[N];
bitset<N> viz;
queue<int> q;
vector<int> P[N];
vector<pair<int,int>> v[N];
vector<tuple<int,int,int>> paths;
void getSolA(int nod)
{
    if(solA[nod])
        return;
    if(!solA[T[nod]])
        getSolA(T[nod]);
    solA[nod]=solA[T[nod]]+CT[nod]-CS[nod];
}
int main()
{
    f>>n>>k;
    for(int i=1;i<n;i++)
    {
        int x,y,c;

        f>>x>>y>>c;
        v[x].push_back(make_pair(y,c));gr[x]++;
        v[y].push_back(make_pair(x,c));gr[y]++;
    }
    for(int i=1;i<=n;i++)
        if(gr[i]==1)
        {
            L[i]=i;
            q.push(i);
        }
    int root;
    while(q.size())
    {

        int nod=q.front();q.pop();
        gr[nod]--;root=nod;
        for(auto it:v[nod])
        {
            int t,c;
            tie(t,c)=it;
            if(gr[t])
            {
                gr[t]--;
                T[nod]=t;
                if(gr[t]==1)
                    q.push(t);
                CT[nod]=CS[nod]+c;
                if(CT[nod]>CS[t])
                {
                    S[t]=nod;
                    CS[t]=CT[nod];
                    L[t]=L[nod];
                }
            }
        }
    }
    CT[root]=CS[root];
    for(int i=1;i<=n;i++)
        if(S[i]==0)
        {
            int x=i,y=T[x],longPath=0,shortPath=0;
            if(v[y].size()>1)
                shortPath=CT[x];
            longPath=CT[x];
            P[i].push_back(x);
            P[i].push_back(y);
            while(S[y]==x)
            {
                x=T[x];y=T[y];
                longPath=CT[x];
                P[p].push_back(y);
                if(v[y].size()>1 && shortPath==0)
                    shortPath=CT[x];
            }
            paths.push_back(make_tuple(longPath,shortPath,i));
    }
    sort(paths.rbegin(),paths.rend());
    int shortPath=get<1>(paths[0]),baza=0,supliment;
    for(int i=0;i<k;i++)
    {
        baza+=get<0>(paths[i]);
        shortPath=min(shortPath,get<1>(paths[i]));
    }
    supliment=get<0>(paths[k]);
    for(int i=0;i<k;i++)
    {
        int leaf=get<2>(paths[i]);
        solA[leaf]=supliment;
        for(auto it:P[leaf])
            solA[it]+=baza;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==root)
            solA[i]=baza;
        getSolA(i);
        int SOL=min(solA[i],solA[i]-shortPath+CS[i]);
        g<<SOL<<'\n';
    }

    return 0;
}
