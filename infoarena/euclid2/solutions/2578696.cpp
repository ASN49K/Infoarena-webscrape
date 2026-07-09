#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

int n, m;
int dist[50001];
vector<pair<int, int> > gr[50001];
priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;


int main(){
    in>>n>>m;
    for(int i=0;i<m;++i){
        int f,t,d;
        in>>f>>t>>d;
        gr[--f].push_back({--t, d});
    }

    fill(dist, dist+n, 1048576);
    dist[0]=0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        if(a.first!=dist[a.second]) continue;
        for(auto i: gr[a.second]){
            if(dist[i.first] > dist[a.second] + i.second){
                dist[i.first] = dist[a.second] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    for(int i=1;i<n;++i){
        if(dist[i]==1048576) out<<"0 ";
        else out<<dist[i]<<' ';
    }

    return 0;
}
