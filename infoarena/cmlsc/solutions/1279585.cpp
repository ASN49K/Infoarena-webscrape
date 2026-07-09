#include<algorithm>
#include<cstdio>
#define MAX_N 100000
using namespace std;

int pre[MAX_N+1];
int d[MAX_N+1];
int aib[MAX_N+1];
int v[MAX_N+1];

int lst[MAX_N+1];

int n;

void update(int x,int ind){
    while(x<=n){
        if (d[aib[x]]<d[ind]) aib[x]=ind;
        else x=n;
        x+=(x&(-x));
    }
}

int query(int x){
    int b=aib[x];

    for(x-=(x&(-x));x>0;x-=(x&(-x)))
        if (d[b]<d[aib[x]]) b=aib[x];

    return b;
}

bool cmp(int a,int b){
    if (v[a]<v[b]) return true;
    return false;
}

void afis(int p){
    if (pre[p]==0){
        printf ("%d ",lst[v[p]]);
        return ;
    }
    afis(pre[p]);
    printf ("%d ",lst[v[p]]);
}

int main(){
    freopen ("scmax.in","r",stdin);
    freopen ("scmax.out","w",stdout);
    int i,k,aux,max;

    scanf ("%d",&n);

    for(i=1;i<=n;i++){
        scanf ("%d",&v[i]);
        lst[i]=i;
    }

    sort(lst+1,lst+n+1,cmp);

    k=0;
    for(i=1;i<=n;i++){
        if (lst[k]!=v[lst[i]]){
            k++;
            aux=v[lst[i]];
            v[lst[i]]=k;
            lst[k]=aux;
        }
        else v[lst[i]]=k;
    }

    for(i=1;i<=n;i++){
        pre[i]=query(v[i]-1);
        d[i]=d[pre[i]]+1;
        update(v[i],i);
    }

    max=d[1];
    aux=1;
    for(i=2;i<=n;i++)
        if (max<d[i]){
            max=d[i];
            aux=i;
        }

    printf ("%d\n",max);

    //afis(aux);
    i=1;
    while(aux!=0){
        d[i]=lst[v[aux]];
        i++;
        aux=pre[aux];
    }

    for(i--;i>0;i--)
        printf ("%d ",d[i]);

    return 0;
}
