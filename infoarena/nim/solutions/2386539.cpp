#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define NMAX 1024
#define INF 0x3f3f3f3f
using namespace std;

int N,M;

int Cap[NMAX][NMAX];
int Flux[NMAX][NMAX];

int Root[NMAX];

bool viz[NMAX];

vector<int> G[NMAX];

int BFS()
{
    int nod,V;

    queue<int> Q;
    Q.push(1);

    for(int i=1;i<=N;i++)
        viz[i]=0;

    viz[1]=1;

    while(!Q.empty())
    {
        nod=Q.front();
        Q.pop();

        if(nod==N)
        {
            nod=Q.front();
            Q.pop();
            if(!Q.empty())
                return viz[N];
        }

        for(auto it:G[nod])
        {
            if(Cap[nod][it]==Flux[nod][it] || viz[it])
                continue;
            viz[it]=1;
            Q.push(it);
            Root[it]=nod;
        }
    }
    return viz[N];
}


void citire()
{
    int a,b,c;
    scanf("%d %d\n",&N,&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d %d %d\n",&a,&b,&c);
        G[a].push_back(b);
        G[b].push_back(a);
        Cap[a][b]+=c;
    }

}

int main()
{

    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);

    citire();

    int flux,fluxmin,nod;

    for(flux=0;BFS();)
    {
        for(auto i:G[N])
        {
            nod=i;

            if(Cap[nod][N]==Flux[nod][N] || !viz[nod])
                continue;

            Root[N]=nod;

            fluxmin=INF;

            for(nod=N;nod!=1;nod=Root[nod])
            {
                fluxmin=min(fluxmin,Cap[Root[nod]][nod]-Flux[Root[nod]][nod]);
            }
            if(fluxmin==0)
                continue;

            for(nod=N;nod!=1;nod=Root[nod])
            {
                Flux[Root[nod]][nod]+=fluxmin;
                Flux[nod][Root[nod]]-=fluxmin;
            }

            flux+=fluxmin;
        }
    }

    printf("%d",flux);

    return 0;
}
