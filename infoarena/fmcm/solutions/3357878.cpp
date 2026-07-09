#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

#include <fstream>
ifstream cin ("maxflow.in");ofstream cout ("maxflow.out");

int cap[1010][1010];
int flow[1010][1010];
vector <pair<int , int>> gr[1010];
queue <int> q;
int dad[1010];
int cost[1010];
int in[1010];

int n , m , s , d;

int bfs(){
    while (!q.empty()) q.pop();
    q.push(s);
    for (int i=1; i<=n; i++){
        dad[i] = 0;
        cost[i] = 1e9;
    }
    cost[s] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        in[now] = 0;
        for (auto &x : gr[now]){
            if (flow[now][x.first] < cap[now][x.first] && cost[x.first] > cost[now] + x.second){
                dad[x.first] = now;
                cost[x.first] = cost[now] + x.second;
                if (!in[x.first]){
                    q.push(x.first);
                    in[x.first] = 1;
                }
            }
        }
    }
    return cost[d];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>s>>d;

    for (int i=1; i<=m; i++){
        int a , b , c , d;
        cin>>a>>b>>c>>d;
        gr[a].push_back({b , d});
        gr[b].push_back({a , -d});

        cap[a][b] += c;
    }

    int ans = 0;

    while (bfs() < 1e9){
        int MIN = 1e9;
        int now = d;
        while (now != s){
            MIN = min(MIN , cap[dad[now]][now] - flow[dad[now]][now]);
            now = dad[now];
        }
        now = d;
        while (now != s){
            flow[dad[now]][now] += MIN;
            flow[now][dad[now]] -= MIN;
            now = dad[now];
        }
        ans += cost[d] * MIN;
    }

    cout<<ans;

    return 0;
}