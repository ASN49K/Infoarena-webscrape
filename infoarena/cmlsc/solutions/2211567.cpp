#include <iostream>
#include <fstream>
#include <vector>
#define len 1025
#define sz 257
#define x first
#define y second
#define pb push_back

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v[len], p[len], pos[sz], N, M, lmax, nr;
vector<int> h;
int main()
{
    in >> N >> M;
    if(N >= M)
    {
        nr = M;
        for(int i = 1; i <= N; ++i)
        {
            in >> v[i];
            pos[v[i]] = i;
        }
        for(int i = 1; i <= M; ++i)
            in >> p[i];
    }
    else{
        nr = N;
        for(int i = 1; i <= N; ++i)
            in >> p[i];
        for(int i = 1; i <= M; ++i)
        {
            in >> v[i];
            pos[v[i]] = i;
        }
    }
    for(int i = 1; i < nr; ++i)
        if(pos[p[i]])
        {
            vector<int> w;
            w.pb(p[i]);
            int last = p[i];
            for(int j = i + 1; j <= nr; ++j)
                if(pos[p[j]] > pos[last])
                {
                    w.pb(p[j]);
                    last = p[j];
                }
            if(w.size() > lmax)
            {
                lmax = w.size();
                for(int k = 0; k < w.size(); ++k)
                    h.pb(w[k]);
            }
        }
    out << lmax << '\n';
    for(int i = 0; i < lmax; ++i)
        out << h[i] << ' ';
    return 0;
}
