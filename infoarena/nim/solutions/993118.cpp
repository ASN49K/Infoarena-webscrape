#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define uv (v[i].nebs[j])
#define flw (v[i].flow[v[i].nebs[j]])

using namespace std;

ifstream f("cuplaj.in");
ofstream g("cuplaj.out");

int n,m;
struct nod{
    vector<int> nebs;
    map<int,int> flow;
};

nod v[20002];

bool bfs(int parent[],int son[]){

    queue<int> q;
    bool ok[20002]={};
    son[0]=0;
    q.push(0);
    ok[0]=1;

    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(unsigned j=0;j<v[i].nebs.size();j++){
            if(uv!=n+m+1&&!ok[uv]&&flw>0){
                ok[uv]=1;
                parent[uv]=i;
                q.push(uv);
            }
            if(uv==n+m+1&&flw>0){
                ok[n+m+1]=1;
                son[++son[0]]=i;
            }
        }
    }

    return ok[n+m+1];
}


int main()
{
    int nr;
    f>>n>>m>>nr;

    for(int i=1;i<=n;i++){
        v[0].nebs.push_back(i);
        v[i].nebs.push_back(0);
        v[0].flow[i]+=1;
        v[i].flow[0]+=0;
    }
    for(int i=1;i<=m;i++){
        v[i+n].nebs.push_back(n+m+1);
        v[n+m+1].nebs.push_back(i+n);
        v[i+n].flow[n+m+1]+=1;
        v[n+m+1].flow[i+n]+=0;
    }
    for(int i=1;i<=nr;i++){
        int x,y;
        f>>x>>y;
        y+=n;
        v[x].nebs.push_back(y);
        v[y].nebs.push_back(x);
        v[x].flow[y]+=1;
        v[y].flow[x]+=0;
    }

    int parent[20002],son[20002];
    int s=0;

    while(bfs(parent,son)){
        for(int t=1;t<=son[0];t++){
            int i=son[t],j=n+m+1,flo=v[i].flow[j];
            while(i){
                j=i;
                i=parent[i];
                flo=min(flo,v[i].flow[j]);
            }
            i=son[t],j=n+m+1;
            v[i].flow[j]-=flo;
            v[j].flow[i]+=flo;
            while(i){
                j=i;
                i=parent[i];
                v[i].flow[j]-=flo;
                v[j].flow[i]+=flo;
            }
            s+=flo;
        }
    }
    g<<s<<'\n';

    for(int i=1;i<=n;i++){
        for(map<int,int>::iterator it=v[i].flow.begin();it!=v[i].flow.end();it++)
            if(it->first&&!it->second){
                g<<i<<" "<<it->first-n<<'\n';
                break;
            }
    }


    return 0;
}
