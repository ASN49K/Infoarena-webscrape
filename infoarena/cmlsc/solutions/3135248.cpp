#include <bits/stdc++.h>
#define optim ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define let auto
#define popcount __builtin_popcount
#define ctzll __builtin_ctzll
#define clzll __builtin_clzll

using namespace std;
string filename = "cmlsc";
ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

vector<int> v1, v2;
vector<int> f1, f2;
int n, m;
/*

5 3
1 7 3 9 8 ...
7 5 8 ...

7 8

3 2 5 7
1 7 4 3 2



*/

vector<int> subsir(vector<int> v1, vector<int> f1, int n, vector<int> v2, vector<int> f2, int m)
{
    vector<int> r;
    int p = 1;
    for (int i = 1; i <= n; ++i)
    {
        int x = v1[i];
        if (f2[x] > 0)
        {

            for (; p <= m; ++p)
            {
                f2[v2[p]]--;
                if (v2[p] == x)
                {
                    r.push_back(x);
                    p++;
                    break;
                }
            }
        }
    }
    cout << '\n';
    return r;
}

int main()
{

    fin >> n >> m;
    v1 = vector<int>(n + 1);
    f1 = vector<int>(257);
    v2 = vector<int>(m + 1);
    f2 = vector<int>(257);
    for (int i = 1; i <= n; ++i)
    {
        fin >> v1[i];
        f1[v1[i]]++;
    }
    for (int i = 1; i <= m; ++i)
    {
        fin >> v2[i];
        f2[v2[i]]++;
    }
    auto r1 = subsir(v1, f1, n, v2, f2, m);
    auto r2 = subsir(v2, f2, m, v1, f1, n);
    if (r1.size() > r2.size())
    {
        fout << r1.size() << '\n';
        for (int i : r1)
            fout << i << ' ';
    }
    else
    {
        fout << r2.size() << '\n';
        for (int i : r2)
            fout << i << ' ';
    }

    return 0;
}