#include <cstdio>
using namespace std;
int v[1001],x[1001],l[1001],next[1001];

int cif_Unu(int n){
    int nr;
    nr=0;
    while(n!=0){
        if(n%2==1){
            nr++;
        }
        n=n/2;
    }
    return nr;
}

int main(){
    freopen("cmlcs.in","r",stdin);
    freopen("cmlcs.out","w",stdout);
    int n,i,j,lmax,poz;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);
        x[i]=cif_Unu(v[i]);
    }
    l[n]=1;
    next[n]=0;
    for(i=n-1;i>=1;i--){
        l[i]=0;
        next[i]=0;
        for(j=i+1;j<=n;j++){
            if(x[i]<=x[j]){
                if(l[j]+1>l[i]){
                    l[i]=l[j]+1;
                    next[i]=j;
                }
            }
        }
    }
    lmax=l[1];
    poz=1;
    for(i=2;i<=n;i++){
        if(l[i]>lmax){
            lmax=l[i];
            poz=i;
        }
    }
    printf("%d\n",lmax);
    while(poz>0){
        printf("%d ",v[poz]);
        poz=next[poz];
    }
    return 0;
}
