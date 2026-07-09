#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int sor[N + 5];
int buck = 700;

struct QRY
{
    int l, r, i;
};

vector<int> stanga[N + 5];
vector<int> dreapta[N + 5];
set<pair<int, int>> ds;

void bagaAfaraStanga(int x, int pos)
{
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.erase({dreapta[x].back() - stanga[x].back(), x});
    stanga[x].push_back(pos);
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.insert({dreapta[x].back() - stanga[x].back(), x});
}
void bagaAfaraDreapta(int x, int pos)
{
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.erase({dreapta[x].back() - stanga[x].back(), x});
    dreapta[x].push_back(pos);
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.insert({dreapta[x].back() - stanga[x].back(), x});
}
void scoateAfaraStanga(int x)
{
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.erase({dreapta[x].back() - stanga[x].back(), x});
    stanga[x].pop_back();
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.insert({dreapta[x].back() - stanga[x].back(), x});
}
void scoateAfaraDreapta(int x)
{
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.erase({dreapta[x].back() - stanga[x].back(), x});
    dreapta[x].pop_back();
    if(!dreapta[x].empty() && !stanga[x].empty())
        ds.insert({dreapta[x].back() - stanga[x].back(), x});
}

int intreb()
{
    if(ds.empty())
        return -1;
    return (*ds.begin()).first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    buck = sqrt(n);

    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        sor[i] = sor[i - 1] ^ x;
    }

    map<int, int> mp;
    for(int i = 0; i <= n; i ++)
        mp[sor[i]] = i;
    for(int i = 0; i <= n; i ++)
        sor[i] = mp[sor[i]];

    int q;
    cin >> q;
    vector<QRY> qry;
    vector<int> ans(q);
    for(int i = 0; i < q; i ++)
    {
        int l, r;
        cin >> l >> r;
        qry.push_back({l + 1, r, i});
    }
    sort(qry.begin(), qry.end(), [&](QRY a, QRY b)
    {
        if(a.l / buck == b.l / buck)
            return a.r < b.r;
        return a.l < b.l;
    });

    for(int i = n; i >= 0; i --)
        bagaAfaraDreapta(sor[i], i);


    int l = 0, r = -1;
    for(int i = 0; i < q; i ++)
    {
        while(r < qry[i].r)
        {
            r ++;
            scoateAfaraDreapta(sor[r]);
        }
        while(r > qry[i].r)
        {
            bagaAfaraDreapta(sor[r], r);
            r --;
        }
        while(l < qry[i].l)
        {
            bagaAfaraStanga(sor[l], l);
            l ++;
        }
        while(l > qry[i].l)
        {
            l --;
            scoateAfaraStanga(sor[l]);
        }
        ans[qry[i].i] = intreb();
    }

    for(auto i : ans)
        cout << i << '\n';
}
