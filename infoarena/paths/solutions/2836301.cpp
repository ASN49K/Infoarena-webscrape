#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define nmax 100001
#define int long long

using namespace std;

struct AINTsum
{
    long long aint[4 * nmax], lazy[4 * nmax], dirty[4 * nmax];
    void propag(int ind, int st, int dr)
    {
        if (dirty[ind])
        {
            aint[ind] = lazy[ind];
            if (st != dr)
                lazy[2 * ind] = lazy[ind], dirty[2 * ind] = 1, lazy[2 * ind + 1] = lazy[ind], dirty[2 * ind + 1] = 1;
            lazy[ind] = 0;
            dirty[ind] = 0;
        }
    }
    void build(int ind, int st, int dr, int h[])
    {
        lazy[ind] = dirty[ind] = 0;
        if (st == dr)
            aint[ind] = h[st];
        else
        {
            build(2 * ind, st, (st + dr) / 2, h);
            build(2 * ind + 1, (st + dr) / 2 + 1, dr, h);
            aint[ind] = aint[2 * ind] + aint[2 * ind + 1];
        }
    }
    void update(int ind, long long val, int stu, int dru, int st, int dr)
    {
        propag(ind, st, dr);
        if (stu <= st && dr <= dru)
        {
            lazy[ind] = val;
            dirty[ind] = 1;
            propag(ind, st, dr);
        }
        else
        {
            if (stu <= (st + dr) / 2)
                update(2 * ind, val, stu, dru, st, (st + dr) / 2);
            if (dru > (st + dr) / 2)
                update(2 * ind + 1, val, stu, dru, (st + dr) / 2 + 1, dr);
            propag(2 * ind, st, (st + dr) / 2), propag(2 * ind + 1, (st + dr) / 2 + 1, dr);
            aint[ind] = aint[2 * ind] + aint[2 * ind + 1];
        }
    }
    long long query(int ind, int stq, int drq, int st, int dr)
    {
        propag(ind, st, dr);
        if (st >= stq && dr <= drq)
            return aint[ind];
        else
        {
            long long maxx = 0;
            if (stq <= (st + dr) / 2)
                maxx = maxx + query(2 * ind, stq, drq, st, (st + dr) / 2);
            if (drq > (st + dr) / 2)
                maxx = maxx + query(2 * ind + 1, stq, drq, (st + dr) / 2 + 1, dr);
            return maxx;
        }
    }
};
struct adiacenta
{
    int nod, val;
};
int lc = 0, f[nmax], leafs[nmax], n, w[nmax], lant[nmax], pos[nmax], asc[nmax], lentoroot[nmax], stlant[nmax], poz = 1, fl = 2, zero[4 * nmax], luat[nmax];
unordered_map<int, unordered_map<int, int>> cost;
AINTsum v, copie;
bool cmp(adiacenta a, adiacenta b)
{
    return w[a.nod] > w[b.nod];
}
vector<adiacenta> ad[nmax];
void dfsleafs(int nod, int p)
{
    int ok = 0;
    for (auto i : ad[nod])
        if (i.nod != p)
            ok = 1, dfsleafs(i.nod, nod);
    if (ok == 0)
        leafs[lc++] = nod;
}
void dfsweight(int nod, int p)
{
    int ok = 0;
    for (auto i : ad[nod])
        if (i.nod != p)
            ok = 1, dfsweight(i.nod, nod);
    for (auto i : ad[nod])
    {
        if (i.nod != p)
            w[nod] += w[i.nod];
    }
}
void dfslant(int nod, int p)
{
    int x = 0;
    pos[nod] = poz++;
    f[nod] = 1;
    v.update(1, (long long)v.query(1, pos[nod], pos[nod], 1, n) + cost[nod][p], pos[nod], pos[nod], 1, n);
    while (x < ad[nod].size() && lant[ad[nod][x].nod])
    {
        x++;
    }
    if (x < ad[nod].size())
    {
        lant[ad[nod][x].nod] = lant[nod];
        for (auto i : ad[nod])
            if (i.nod != p && i.nod != ad[nod][x].nod && f[i.nod] == 0)
                lant[i.nod] = fl, asc[fl] = nod, lentoroot[fl] = lentoroot[lant[nod]] + 1, stlant[fl] = i.nod, fl++;
        for (auto i : ad[nod])
            if (i.nod != p && f[i.nod] == 0)
                dfslant(i.nod, nod);
    }
}
long long sum(int x, int y)
{
    long long s = 0;
    while (lant[x] != lant[y])
    {
        if (lentoroot[lant[x]] < lentoroot[lant[y]])
            swap(x, y);
        if (lant[x] == 1)
            swap(x, y);
        s += v.query(1, pos[stlant[lant[x]]], pos[x], 1, n);
        x = asc[lant[x]];
    }
    if (w[x] > w[y])
        swap(x, y);
    s += v.query(1, pos[y], pos[x], 1, n);
    return s;
}
void upsum(int x, int y)
{
    while (lant[x] != lant[y])
    {
        if (lentoroot[lant[x]] < lentoroot[lant[y]])
            swap(x, y);
        if (lant[x] == 1)
            swap(x, y);
        //cout << stlant[lant[x]] << " " << pos[x] << " " << v.query(1, stlant[lant[x]], pos[x], 1, n) << endl;
        v.update(1, 0, pos[stlant[lant[x]]], pos[x], 1, n);
        //cout << stlant[lant[x]] << " " << pos[x] << " " << v.query(1, stlant[lant[x]], pos[x], 1, n) << endl;
        x = asc[lant[x]];
    }
    if (w[x] > w[y])
        swap(x, y);
    //cout << pos[y] << " " << pos[x] << " " << v.query(1, pos[y], pos[x], 1, n) << endl;
    v.update(1, 0, pos[y], pos[x], 1, n);
    //cout << pos[y] << " " << pos[x] << " " << v.query(1, pos[y], pos[y], 1, n) << endl;
}

signed main()
{
    ifstream cin("paths.in");
    ofstream cout("paths.out");
    int k, i, j, a, b, c, x = 1, ck, maxpoz, clc;
    long long maxx = 0, tot = 0, aux;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        ad[a].push_back({b, c});
        ad[b].push_back({a, c});
        cost[a][b] = cost[b][a] = c;
    }
    if (n != 1)
    {
        for (i = 0; i <= 4 * n; i++)
            zero[i] = 0;
        lc = 0;
        for (i = 1; i <= n; i++)
            pos[i] = lant[i] = asc[i] = lentoroot[i] = 0, w[i] = 1;
        dfsweight(1, 0);
        for (i = 1; i <= n; i++)
        {
            w[i]--;
            sort(ad[i].begin(), ad[i].end(), cmp);
        }
        v.build(1, 1, n, zero);
        lant[x] = 1,
        fl = 2, poz = 1, stlant[1] = x;
        dfslant(1, 1);
        for (i = 0; i <= 4 * n; i++)
            copie.aint[i] = v.aint[i];
    }
    while (x <= n)
    {
        if (n != 1)
        {
            lc = 0;
            dfsleafs(x, 0);
            clc = lc;
            ck = k, tot = 0;
            while (ck && clc)
            {
                maxx = 0;
                for (i = 0; i < lc; i++)
                {
                    if (!luat[leafs[i]])
                    {
                        aux = sum(x, leafs[i]);
                        //cout << x << " " << leafs[i] << " " << aux << endl;
                        if (aux > maxx)
                            maxx = aux, maxpoz = leafs[i];
                    }
                }
                if (maxx > 0)
                    upsum(x, maxpoz);
                else
                    break;
                luat[maxpoz] = 1;
                tot += maxx;
                ck--;
                clc--;
            }
            for (i = 0; i <= 4 * n; i++)
            {
                if (i <= n)
                    luat[i] = 0;
                v.dirty[i] = v.lazy[i] = 0, v.aint[i] = copie.aint[i];
            }
        }
        cout << tot << '\n';
        x++;
    }
    return 0;
}