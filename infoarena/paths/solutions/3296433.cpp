#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("paths.in");
ofstream g("paths.out");

const long long nmax = 1e5 + 5;

struct ceva{
    long long x, c;
};

long long n, k, fr[nmax];
vector<ceva> v[nmax];
priority_queue<long long> H;

void idk(long long nod, long long sum)
{
    long long maxi = 0, oki = 0;
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
    for(long long i = 1; i < n; i ++)
    {
        long long x, y, c; f >> x >> y >> c;
        v[x].push_back({y, c});
        v[y].push_back({x, c});
    }

    for(long long i = 1; i <= n; i ++)
    {
        idk(i, 0);

        long long sumi = 0;
        for(long long j = 1; j <= k; j ++)
            sumi += H.top(), H.pop();

        for(long long j = 1; j <= n; j ++) fr[j] = 0;
        while(!H.empty()) H.pop();

        g << sumi << '\n';
    }
    return 0;
}
