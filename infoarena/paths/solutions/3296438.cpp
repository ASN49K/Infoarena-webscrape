#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("paths.in");
ofstream g("paths.out");

const int nmax = 1e5 + 5;

struct ceva{
    int x, c;
};

int n, k, cost[nmax];
vector<ceva> v[nmax];
priority_queue<int> H;

void idk(int nod, int t)
{
    int poz = 0;

    for(auto [x, c] : v[nod])
    {
        if(x == t) continue;

        idk(x, nod);
        cost[x] += c;

        if(cost[nod] < cost[x])
            cost[nod] = cost[x], poz = x;
    }

    if(t == -1)
        poz = 0;

    for(auto [x, c] : v[nod])
        if(x != poz && x != t)
            H.push(cost[x]);
}

int main()
{
    f >> n >> k;
    for(int i = 1; i < n; i ++)
    {
        int x, y, c; f >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }

    for(int i = 1; i <= n; i ++)
    {
        idk(i, -1);

        int sumi = 0;
        for(int j = 1; j <= k && !H.empty(); j ++)
            sumi += H.top(), H.pop();

        for(int j = 1; j <= n; j ++) cost[j] = 0;
        while(!H.empty()) H.pop();

        g << sumi << '\n';
    }
    return 0;
}
