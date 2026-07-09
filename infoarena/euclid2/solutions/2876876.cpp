#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, a, b;
vector<pair<int,int>>v;
vector<int>ans;

void ReadInput()
{
    f >> T;
    for(int i=0;i<T;++i)
    {
        f >> a >> b;
        v.push_back({a,b});
    }
}

void Solution()
{
    for(int i=0;i<v.size();++i)
    {
        int aa = v[i].first;
        int bb = v[i].second;
        while(bb)
        {
            int r = aa%bb;
            aa = bb;
            bb = r;
        }
        ans.push_back(aa);
    }
}

void Output()
{
    for(int i=0;i<ans.size();++i)
        g << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadInput();
    Solution();
    Output();
    return 0;
}
