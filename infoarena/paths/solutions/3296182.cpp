#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node
{
    Node *st, *dr;
    int val,prior,sz,sum;
};

Node nil;
Node *T = &nil;

mt19937 my_rand(time(NULL));

int n,k;

int Max[100005],Max2[100005],d[100005];

vector<pair<int,int>> Gaux[100005];
vector<int> G[100005];

int l[100005];

int rez[100005];

Node *modfiu(Node *nod, bool care, Node *son)
{
    if(care==0)
    {
        nod -> st = son;
    }
    else
    {
        nod -> dr = son;
    }
    nod -> sz = nod->st->sz + 1 + nod->dr->sz;
    nod -> sum = nod->st->sum + nod->val + nod->dr->sum;
    return nod;
}

Node *join(Node *st, Node *dr)
{
    if(st==&nil)
    {
        return dr;
    }
    if(dr==&nil)
    {
        return st;
    }
    if(st->prior>=dr->prior)
    {
        return modfiu(st,1,join(st->dr,dr));
    }
    return modfiu(dr,0,join(st,dr->st));
}

pair<Node*,Node*> split(Node *nod, int k)
{
    if(nod==&nil)
    {
        return {&nil,&nil};
    }
    if(nod->st->sz>=k)
    {
        auto t = split(nod->st,k);
        return {t.first,modfiu(nod,0,t.second)};
    }
    auto t = split(nod->dr,k - nod->st->sz - 1);
    return {modfiu(nod,1,t.first),t.second};
}

int Search(Node *nod, int val)
{
    if(nod==&nil)
    {
        return 0;
    }
    if(val>=nod->val)
    {
        return nod->st->sz + 1 + Search(nod->dr,val);
    }
    return Search(nod->st,val);
}

void Add(int val)
{
    int poz = Search(T,val);
    auto t = split(T,poz);
    T = join(t.first,join(new Node{&nil,&nil,val,my_rand(),1,val},t.second));
}

void Remove(int val)
{
    int poz = Search(T,val);
    auto t = split(T,poz-1);
    auto t2 = split(t.second,1);
    T = join(t.first,t2.second);
}

int kmax()
{
    auto t = split(T,T -> sz - k);
    int rez = t.second -> sum;
    T = join(t.first,t.second);
    return rez;
}

void preset(int nod, int dad = 0)
{
    for(auto it : Gaux[nod])
    {
        if(it.first==dad)
        {
            continue;
        }
        preset(it.first,nod);
        d[it.first] = it.second;
    }
}

void dfs(int nod, int dad = 0)
{
    for(auto it : G[nod])
    {
        if(it==dad)
        {
            continue;
        }
        dfs(it,nod);
        if(l[it] + d[it] > l[Max[nod]] + d[Max[nod]])
        {
            Max2[nod] = Max[nod];
            Max[nod] = it;
        }
        else if(l[it] + d[it] > l[Max2[nod]] + d[Max2[nod]])
        {
            Max2[nod] = it;
        }
    }
    l[nod] = l[Max[nod]] + d[Max[nod]];
    for(auto it : G[nod])
    {
        if(it==dad || it==Max[nod])
        {
            continue;
        }
        Add(l[it] + d[it]);
    }
}

void dfs_solve(int nod, int dad = 0, int lsus = 0, bool mergsus = false)
{
    rez[nod] = kmax();
    for(auto it : G[nod])
    {
        if(it==dad)
        {
            continue;
        }
        if(mergsus)
        {
            int new_l = max(l[it],lsus + d[it]);
            int new_lsus = d[it] + lsus;
            bool new_mergsus = false;
            Remove(lsus);
            Add(new_l);
            Remove(l[it] + d[it]);
            if(new_l!=l[it])
            {
                new_mergsus = true;
                Add(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                new_mergsus = false;
                Add(new_lsus);
            }
            dfs_solve(it,nod,new_lsus,new_mergsus);
            if(new_l!=l[it])
            {
                Remove(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                Remove(new_lsus);
            }
            Add(l[it] + d[it]);
            Remove(new_l);
            Add(lsus);
            continue;
        }
        if(it!=Max[nod])
        {
            int new_l = max(l[it],l[nod] + d[it]);
            int new_lsus = d[it] + l[nod];
            bool new_mergsus = false;
            Remove(l[nod]);
            Add(new_l);
            Remove(l[it] + d[it]);
            if(new_l!=l[it])
            {
                new_mergsus = true;
                Add(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                new_mergsus = false;
                Add(new_lsus);
            }
            dfs_solve(it,nod,new_lsus,new_mergsus);
            if(new_l!=l[it])
            {
                Remove(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                Remove(new_lsus);
            }
            Add(l[it] + d[it]);
            Remove(new_l);
            Add(l[nod]);
            continue;
        }
        if(lsus > l[Max2[nod]] + d[Max2[nod]])
        {
            int new_l = max(l[it],lsus + d[it]);
            int new_lsus = d[it] + lsus;
            bool new_mergsus = false;
            Remove(l[nod]);
            Add(new_l);
            Remove(lsus);
            if(new_l!=l[it])
            {
                new_mergsus = true;
                Add(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                new_mergsus = false;
                Add(lsus + d[it]);
            }
            dfs_solve(it,nod,new_lsus,new_mergsus);
            if(new_l!=l[it])
            {
                Remove(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                Remove(lsus + d[it]);
            }
            Add(lsus);
            Remove(new_l);
            Add(l[nod]);
        }
        else
        {
            int new_l = max(l[it],l[Max2[nod]] + d[Max2[nod]] + d[it]);
            int new_lsus = d[it] + l[Max2[nod]] + d[Max2[nod]];
            bool new_mergsus = false;
            Remove(l[nod]);
            Add(new_l);
            if(Max2[nod])
            {
                Remove(l[Max2[nod]] + d[Max2[nod]]);
            }
            if(new_l!=l[it])
            {
                new_mergsus = true;
                Add(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                new_mergsus = false;
                Add(l[Max2[nod]] + d[Max2[nod]] + d[it]);
            }
            dfs_solve(it,nod,new_lsus,new_mergsus);
            if(new_l!=l[it])
            {
                Remove(l[Max[it]] + d[Max[it]]);
            }
            else
            {
                Remove(l[Max2[nod]] + d[Max2[nod]] + d[it]);
            }
            if(Max2[nod])
            {
                Add(l[Max2[nod]] + d[Max2[nod]]);
            }
            Remove(new_l);
            Add(l[nod]);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("paths.in","r",stdin);
    freopen("paths.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        Gaux[x].push_back({y,c});
        Gaux[y].push_back({x,c});
        G[x].push_back(y);
        G[y].push_back(x);
    }
    preset(1);
    dfs(1);
    Add(l[1]);
    dfs_solve(1);
    for(int i=1; i<=n; i++)
    {
        cout<<rez[i]<<'\n';
    }
    return 0;
}
