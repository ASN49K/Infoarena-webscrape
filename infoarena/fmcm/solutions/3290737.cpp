//Edmonds Karp + Dijkstra cu potentiale
//O(m^2 * n log n)
#include <bits/stdc++.h>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int inf = 0x3f3f3f3f;

vector < vector <int> > G(351);

int d[351];
int t[351];

int pot[351];
int pot2[351];

bitset <351> in_queue;
bitset <351> viz;
queue <int> q;

int n, s2, t2, cnt_id;

int c[351][351];
int w[351][351];

set < pair <int, int> > s;

void bellman_ford(){
    memset(pot, 0x3f, sizeof pot);
    memset(t, 0, sizeof t);
    q.push(s2);
    pot[s2] = 0;
    in_queue[s2] = 1;
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        in_queue[nod] = 0;
        for(auto x : G[nod]){
            if(c[nod][x] > 0 && pot[x] > pot[nod] + w[nod][x]){
                pot[x] = pot[nod] + w[nod][x];
                t[x] = nod;
                if(!in_queue[x]){
                    q.push(x);
                    in_queue[x] = 1;
                }
            }
        }
    }
}

int dijkstra(){
    memset(d, 0x3f, sizeof d);
    memset(t, 0, sizeof t);
    pot2[s2] = d[s2] = 0;
    s.insert({0, s2});
    viz.reset();
    while(!s.empty()){
        auto it = s.begin();
        int nod = it->second;
        s.erase(it);
        if(viz[nod]) continue;
        viz[nod] = 1;
        for(auto x : G[nod]){
            if(c[nod][x] > 0 && d[x] > d[nod] + w[nod][x] + pot[nod] - pot[x]){
                d[x] = d[nod] + w[nod][x] + pot[nod] - pot[x];
                pot2[x] = pot[nod] + w[nod][x];
                t[x] = nod;
                s.insert({d[x], x});
            }
        }
    }
    for(int i = 1; i <= n; i++) pot[i] = pot2[i];
    return d[t2];
}

int edmonds_karp(){
    int max_flow = 0, rez = 0;
    while(dijkstra() != inf){
        int new_flow = 1e9;
        for(int temp = t2; temp != s2; temp = t[temp]) new_flow = min(new_flow, c[t[temp]][temp]);
        for(int temp = t2; temp != s2; temp = t[temp]){
            c[t[temp]][temp] -= new_flow;
            c[temp][t[temp]] += new_flow;
            rez += new_flow * w[t[temp]][temp];
        }
    }
    return rez;
}

int main()
{
    int i,m,x,y;
    fin >> n >> m >> s2 >> t2;
    while(m--){
        fin >> x >> y;
        fin >> c[x][y] >> w[x][y];
        c[y][x] = 0;
        w[y][x] = -w[x][y];
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bellman_ford();
    fout << edmonds_karp();
    return 0;
}
