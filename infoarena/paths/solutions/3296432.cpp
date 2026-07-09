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

int n, k, fr[nmax];
vector<ceva> v[nmax];
priority_queue<int> H;

void idk(int nod, int sum)
{
    int maxi = 0, oki = 0;
    fr[nod] = 1;

    for(auto [x, c] : v[nod])
        if(!fr[x])
            maxi = max(maxi, c), oki = 1;

    if(!oki)
        H.push(sum);

    for(auto [x, c] : v[nod]){
        if(fr[x])
            continue;

        if(maxi == c && oki)
        {
            oki = 0;
            idk(x, sum + c);
        }

        else
            idk(x, c);
    }
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
        idk(i, 0);

        int sumi = 0;
        for(int j = 1; j <= k; j ++)
            sumi += H.top(), H.pop();

        for(int j = 1; j <= n; j ++) fr[j] = 0;
        while(!H.empty()) H.pop();

        g << sumi << '\n';
    }
    return 0;
}
