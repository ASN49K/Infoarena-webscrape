#include <cstdio>
#include <list>
#define maxn 100005
#include <queue>
#include <stack>

using namespace std;

int N,M,d[maxn];
list < int > G[maxn],A;
queue <int> Q;
bool vis[maxn];
stack <int> S;

void read();
void rez();
void BFS(int);

int main(){
    freopen("ciclueuler.in","r",stdin);
    freopen("ciclueuler.out","w",stdout);
    read();
    rez();
    return 0;
}
void read(){
    scanf("%d %d ",&N,&M);
    int x,y;
    while(M--){
        scanf("%d %d ",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        d[x]++;d[y]++;
    }
}
void BFS(int x){
    Q.push(x);
    vis[x]=true;
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(list <int> :: iterator it=G[x].begin();it!=G[x].end();++it)
            if(vis[*it]==false){
                vis[*it]=true;
                Q.push(*it);
            }
    }
}
void rez(){
    int i,v,w;
    BFS(1);
    for(i=1;i<=N;++i)if(d[i]%2==1){printf("-1\n");return;}
    for(i=1;i<=N;++i)if(vis[i]==false){printf("-1\n");return;}
    v=1;
    do{///cautam un ciclu oarecare:
      while(!G[v].empty()){
          w=G[v].front();
           ///plasam v in stiva:
          S.push(v);
          ///stergem muchia v-w:
          d[v]--;
          d[w]--;
          G[v].pop_front();
          for(list <int> :: iterator it=G[w].begin();it!=G[w].end();++it)
             if(*it==v){
                G[w].erase(it);
                break;
             }
          v=w;
        }
        v=S.top();
        S.pop();
        A.push_back(v);
    }while(!S.empty());
    for(list <int>::iterator it=A.begin();it!=A.end();++it)printf("%d ",*it);
    printf("\n");
}
