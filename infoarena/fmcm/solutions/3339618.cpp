#include <bits/stdc++.h>
#define nmx 355
using namespace std;
int N,M,S,D,F,FCst,old_d[nmx],d[nmx],real_d[nmx],p[nmx];
int C[nmx][nmx], Cst[nmx][nmx];
vector<int> con[nmx];
char inQ[nmx];
queue<int> Q;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> H;
inline bool dijkstra()
{
    memset(d,0x3f,sizeof(d));
    d[S]=0;
    real_d[S]=0;
    H.push(make_pair(d[S],S));
    for (; !H.empty(); )
    {
        int cst=H.top().first,nod=H.top().second;
        H.pop();
        if (d[nod]!=cst)
            continue;
        vector<int> :: iterator it;
        for (it=con[nod].begin(); it!=con[nod].end(); it++)
            if (C[nod][*it])
            {
                int new_d=d[nod]+Cst[nod][*it]+old_d[nod]-old_d[*it];
                if (new_d<d[*it])
                {
                    d[*it]=new_d;
                    real_d[*it]=real_d[nod]+Cst[nod][*it];
                    p[*it]=nod;
                    H.push(make_pair(d[*it],*it));
                }
            }
    }
    memcpy(old_d,real_d,sizeof(d));
    if (d[D]==0x3f3f3f3f)
        return false;
    int Min=0x3f3f3f3f,curCst=0;
    for (int aux=D; aux!=S; aux=p[aux])
    {
        Min=min(Min,C[p[aux]][aux]);
        curCst+=Cst[p[aux]][aux];
    }
    F+=Min;
    FCst+=Min*real_d[D];
    for (int aux=D; aux!=S; aux=p[aux])
        C[p[aux]][aux]-=Min,C[aux][p[aux]]+=Min;
    return true;
}

inline bool bellmanFord()
{
    memset(old_d,0x3f,sizeof(old_d));
    old_d[S]=0;
    for (Q.push(S),inQ[S]=1; !Q.empty(); Q.pop())
    {
        vector<int> :: iterator it;
        int i=Q.front();
        inQ[i]=0;
        for (it=con[i].begin(); it!=con[i].end(); it++)
            if (C[i][*it])
            {
                if (old_d[i]+Cst[i][*it]>=old_d[*it])
                    continue;
                old_d[*it]=old_d[i]+Cst[i][*it];
                if (inQ[*it])
                    continue;
                inQ[*it]=1;
                Q.push(*it);
            }
    }
    if (old_d[D]==0x3f3f3f3f)
        return false;
    return true;
}
int main()
{
    ifstream f ("fmcm.in");
    ofstream g ("fmcm.out");
    f>>N>>M>>S>>D;
    for (; M; M--)
    {
        int x, y;
        f>>x>>y;
        con[x].push_back(y);
        con[y].push_back(x);
        f>>C[x][y]>>Cst[x][y];
        Cst[y][x]=-Cst[x][y];
    }
    F=FCst=0;
    bellmanFord();
    for (; dijkstra(); )
        ;
    g<<FCst;
}
