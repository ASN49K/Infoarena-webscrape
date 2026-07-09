//se dau 2 siruri x si y de n, respectiv m, nr intregi. sa se determine un subsir comun de lungime maxima
//2 5 5 6 2 8 4 0 1 3 5 8
//6 2 5 6 5 5 4 3 5 8
//------> 2 5 5 4 3 5 8
#include<bits/stdc++.h>
#define N 1030
using namespace std;
int x[N],y[N],n,m,c[N][N],r[N],size_r;

void read()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&y[i]);
}

void calc();
void aflare();
void afisare()
{
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=m;j++)
    cout<<c[i][j]<<' ';
    cout<<endl;
    }

}

int main()
{
    int i,j;
    read();
    for(i=0;i<=m;i++)
         c[0][i]=0;
    for(i=0;i<=n;i++)
        c[i][0]=0;
freopen("cmlsc.out","w",stdout);
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
   else c[i][j]=max(c[i-1][j],c[i][j-1]);
cout<<c[n][m]<<'\n';
//afisare();
aflare();


}

void aflare()
{
    int i=n,j=m,pivot=c[n][m];
    while(c[i][j])
        if(x[i]==y[j]) {r[++size_r]=x[i];
                i--;
                j--;
        }
        else if(c[i-1][j]>c[i][j-1]) i--;
        else j--;
for(i=size_r;i>0;i--) cout<<r[i]<<' ';
}

//pachete
/*#include<bits/stdc++.h>
using namespace std;
int desc[100],inst[100],sol[100],n;

void read()
{
    freopen("pachete.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&inst[i],&desc[i]);
}

void solve()
{
    int i;
    sol[n]=desc[n];
    for(i=n-1;i>0;i--) sol[i]+=desc[i]+max(0,sol[i+1]-inst[i]);
    cout<<sol[1];
   // for(i=n;i>0;--i) cout<<sol[i];
}

int main()
{
    read();
    solve();
}*/

//cod,oji 2003 (formule,zmeu)

//cuplaj maxim in graf bipartit

/*#include<bits/stdc++.h>
using namespace std;
ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");
#define N 10005
#define Dim 1000000000

vector <int> G[N+2];
queue <int> q;
int n,m,sol[N],s,t,pred[N],e,C[N][N],f[N][N];
bool viz[N];


void read()
{
    fin>>n>>m>>e;
    s=0;
    t=n+m+1;
    for(int i=1;i<=n;i++)
        {
            G[s].push_back(i);
            G[i].push_back(s);
            C[s][i]=1;
        }
    for(int i=n+1;i<=n+m;i++)
       {
           G[i].push_back(t);
           G[t].push_back(i);
           C[i][t]=1;
       }

        for(int i=1;i<=e;i++)
        {
            int x,y;
            fin>>x>>y;
            G[x].push_back(y+n);
            G[y+n].push_back(x);
            C[x][y+n]=1;
        }

}

bool bfs()
{
    int i,j,nod,nod2;
    memset(viz,0,sizeof(viz));
    q.push(s);
    viz[s]=1;
    while(!q.empty())
    {
            nod=q.front();
            q.pop();
            if(nod==t) continue;
            for(j=0;j<G[nod].size();j++)
            {
                nod2=G[nod][j];
                if(viz[nod2] || f[nod][nod2]==C[nod][nod2]) continue;
                viz[nod2]=1;
                q.push(nod2);
                pred[nod2]=nod;
            }
    }
    return viz[t];

}

int ford_fulkerson()
{


    int flow,i,f_min,nod,pj;
    for(flow=0;bfs();)
        for(i=0;i<G[t].size();i++)
     {
        pj=G[t][i];
        if(!viz[pj] || f[pj][t]==C[pj][t]) continue;
        pred[t]=pj;
        nod=t;
        f_min=Dim;
        while(nod!=s)
        {
            f_min=min(f_min,C[pred[nod]][nod]-f[pred[nod]][nod]);
            nod=pred[nod];
        }
        if(!f_min) continue;

        nod=t;
        while(nod!=s)
        {
            f[pred[nod]][nod]+=f_min;
            f[nod][pred[nod]]-=f_min;
            nod=pred[nod];
        }
        flow+=f_min;
    }


    return flow;
}

void detsol()
{
    for(int i=s+1;i<=n;i++)
        for(int j=0;j<G[i].size();j++)
        if(f[i][G[i][j]]==1) fout<<i<<' '<<G[i][j]-n<<endl;

}

int main()
{
read();
fout<<ford_fulkerson()<<endl;
detsol();
}*/

//cuplaj maxim de cost minim

/*#include<bits/stdc++.h>
#define Dim 2000000000
#define N 710
using namespace std;

int n,m,e,Cost[N][N];
int pred[N],dist[N],C[N][N],f[N][N],s,t,k,M[N][N];
bool viz[N];
struct muchie{int a,b;};

vector <int> G[N];
queue <int> q;

void build()
{
    freopen("cmcm.in","r",stdin);
    scanf("%d %d %d",&n,&m,&e);
    s=0;
    t=n+m+1;
    for(int i=1;i<=n;i++)
    {
        G[s].push_back(i);
        G[i].push_back(s);
        Cost[s][i]=Cost[i][s]=0;
        C[s][i]=1;
    }
    for(int i=n+1;i<=n+m;i++)
    {
        G[i].push_back(t);
        G[t].push_back(i);
        Cost[i][t]=Cost[t][i]=0;
        C[i][t]=1;
    }
    for(int i=1;i<=e;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        G[x].push_back(y+n);
        G[y+n].push_back(x);
        M[x][y+n]=i;
        Cost[x][y+n]=z;
        Cost[y+n][x]=-z;
        C[x][y+n]=1;
    }
}

bool still;

int Edmond()
{
    int i,j,ok=0,h=0,nod,u=1;
    for(i=s;i<=t;i++)
    {
        dist[i]=Dim;
        pred[i]=-1;
    }
    dist[s]=0;
    memset(viz,0,sizeof(viz));
q.push(s);
viz[s]=1;

        while(!q.empty())
          {
             nod=q.front();
             q.pop();

             for(j=0;j<G[nod].size();j++)
            if(C[nod][G[nod][j]]>f[nod][G[nod][j]] && dist[nod]+Cost[nod][G[nod][j]]<dist[G[nod][j]])
        {
            dist[G[nod][j]]=dist[nod]+Cost[nod][G[nod][j]];
            pred[G[nod][j]]=nod;
            if(!viz[G[nod][j]])
            {
                q.push(G[nod][j]);
                viz[G[nod][j]]=1;
            }
        }
           viz[nod]=0;
          }


    if(dist[t]!=Dim)
    {
        still=1;
        int aleg=Dim;
        for(i=t;i!=s;i=pred[i])
            aleg=min(aleg,C[pred[i]][i]-f[pred[i]][i]);

        for(i=t;i!=s;i=pred[i])
        {
            f[pred[i]][i]+=aleg;
            f[i][pred[i]]-=aleg;
        }
        return aleg*dist[t];

    }
    return 0;

}

void care()
{ int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<t;j++)
        if(f[i][j] && C[i][j] ) {ans++;
        break;
        }
        cout<<ans<<' ';
}

void answer()
{
    long long R=0;
    still=1;
    while(still)
    {
        still=0;
        //cout<<Edmond()<<' ';
        R+=Edmond()*1ll;
        //cout<<R<<endl;
    }
    care();
    cout<<R<<'\n';
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<t;j++)
        if(f[i][j] && C[i][j] )
        {
            cout<<M[i][j]<<' ';
            break;
        }

}

int main()
{
    build();
    freopen("cmcm.out","w",stdout);
    //cout<<Edmond();
    answer();
}*/









