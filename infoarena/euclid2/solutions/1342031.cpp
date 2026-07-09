/* Bellman-ford implementation */
#include <fstream>
#include <vector>
#include <queue>
#define VMAX 50002
#define infinite 0x3f3f3f3f
using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

int n,m,s;

struct edge{
    int w;
    int to;
    edge *next;
};

struct node{
    int n;
    node* next;
};

edge* G[VMAX];
queue <int> heap;
int nr[VMAX]; // Ciclu negativ detect
bool heap_aux[VMAX];
int dist[VMAX];

void add(struct edge **l, int n, int w)
{
    edge *p = new edge;
    p->to=n;
    p->w=w;
    p->next = *l;
    *l=p;
}

int bellman()
{
    
    // initializam graph-ul
    for(int i=1; i<=n; ++i)
        dist[i]=infinite;
    dist[1]=0;
    heap.push(1);
    while(!heap.empty()){
        int u = heap.front();
        heap_aux[u]=0;
            for(edge *p=G[u]; p; p=p->next)
                if(dist[u] + p->w < dist[p->to]){
                    if(++nr[u]>=n)
                        return false;
                    dist[p->to] = dist[u] + p->w;
                    if(heap_aux[p->to]==0)
                        heap.push(p->to);
                    heap_aux[p->to]=1;
                }
        heap.pop();
    }
    return 1;
}

void read()
{
    fin>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        int a,b,c;
        fin>>a>>b>>c;
        add(&G[a], b, c);
    }
}

int main()
{
    read();
    if(bellman())
        for(int i=2; i<=n; ++i)
            fout<<dist[i]<<" ";
    else
        fout<<"Ciclu negativ!";
    
    return 0;
}

