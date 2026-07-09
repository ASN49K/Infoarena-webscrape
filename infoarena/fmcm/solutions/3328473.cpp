#include <bits/stdc++.h>
//#pragma GCC optimize ("03")
#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#define FILES freopen("fmcm.in" , "r" , stdin) , freopen("fmcm.out" , "w" , stdout)
#define ll long long
#define ull unsigned long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define qwerty1 first
#define qwerty2 second
#define qwerty3 -> first
#define qwerty4 -> second
#define umap unordered_map
#define uset unordered_set
#define pii pair < ll , ll >
#define dbg(x) cerr << #x << ": " << x << '\n'

namespace FastRead
{
    char __buff[5000];ll __lg = 0 , __p = 0;
    char nc()
    {
        if(__lg == __p){__lg = fread(__buff , 1 , 5000 , stdin);__p = 0;if(!__lg) return EOF;}
        return __buff[__p++];
    }
    template<class T>void read(T&__x)
    {
        T __sgn = 1; char __c;while(!isdigit(__c = nc()))if(__c == '-')__sgn = -1;
        __x = __c - '0';while(isdigit(__c = nc()))__x = __x * 10 + __c - '0';__x *= __sgn;
    }
}

using namespace FastRead;
using namespace std;
#define int long long

const ll N = 2e5 + 10;
const ll M = 1e9 + 7;
const ld PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n , m , source , sink;

struct FMCM 
{
    #define N 350 + 10

    int n , source , sink;
    int cap[N][N] , cost[N][N] , adj[N][N];
    queue < int > q;
    priority_queue < pii , vector < pii > , greater < pii > > pq;
    int dst[N] , d[N];
    int parent[N];

    void add_edge(int x , int y , int c , int z) 
    {
        adj[x][y] = 1;
        adj[y][x] = 1;
        cap[x][y] = c;
        cap[y][x] = 0;
        cost[x][y] = z;
        cost[y][x] = -z;
    }

    void bellman()
    {
        q.push(source);
        
        for(int i = 1 ; i <= n ; i++)
            d[i] = INT_MAX;

        d[source] = 0;
        int iter = 0;

        while(q.size())
        {
            int node = q.front();
            q.pop();
            iter++;

            for(int i = 1 ; i <= n ; i++)
                if(cap[node][i] && adj[node][i] && d[i] > d[node] + cost[node][i])
                {
                    d[i] = d[node] + cost[node][i];
                    q.push(i);
                }
        }
    }

    bool djikstra()
    {
        for(int i = 1 ; i <= n ; i++)
            dst[i] = INT_MAX , parent[i] = -1;

        dst[source] = 0;
        pq.push({0 , source});

        while(pq.size())
        {
            int node = pq.top().second;
            int dd = pq.top().first;
            pq.pop();

            if(dd != dst[node])
                continue;

            for(int i = 1 ; i <= n ; i++)
                if(adj[node][i] && cap[node][i] && dst[i] > dst[node] + cost[node][i] + d[node] - d[i])
                {
                    dst[i] = dst[node] + cost[node][i] + d[node] - d[i];
                    parent[i] = node;
                    pq.push({dst[i] , i});
                }
        }

        return dst[sink] != INT_MAX;
    }

    void init(int n , int source , int sink)
    {
        this -> n = n;
        this -> source = source;
        this -> sink = sink;
    }

    pii max_flow_min_cost()
    {
        bellman();

        int f = 0 , total = 0;

        while(djikstra())
        {
            int flow = INT_MAX;

            int node = sink;

            while(node != source)
            {
                int par = parent[node];
                flow = min(flow , cap[par][node]);
                node = par;
            }

            node = sink;
            int cst = 0;

            while(node != source)
            {
                int par = parent[node];
                cap[par][node] -= flow;
                cap[node][par] += flow;
                cst += flow * cost[par][node];
                node = par;
            }

            f += flow;
            total += cst;
        }

        return {f , total};
    }
}F;

signed main()
{
    FastIO;
	
   // #ifndef ONLINE_JUDGE
		FILES;
//	#endif
    

    cin >> n >> m >> source >> sink;
    F.init(n , source , sink);

    for(int i = 1 ; i <= m ; i++)
    {
        int x , y , cap , cost;

        cin >> x >> y >> cap >> cost;
        F.add_edge(x , y , cap , cost);
    }

    cout << F.max_flow_min_cost().second;

    return 0;
}