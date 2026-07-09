#include<stdio.h>
int nr[1025][1025],a[1025],b[1025],n,m,sol[1025];

inline int max(int a,int b){return a>b ? a:b;};

void solve(){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(a[i]==b[j]) nr[i][j]=1+nr[i-1][j-1];
            else nr[i][j]=max(nr[i-1][j],nr[i][j-1]);
        }
    }
}

int main(){
    int i,j,s,ct=0;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    solve(); s=nr[n][m]; printf("%d\n",s);
    i=n; j=m;
    while(ct<s){
        if(a[i]==b[j]){sol[++ct]=a[i];j--;i--;}
        else{
            if(nr[i][j-1]>nr[i-1][j]) j--; else i--;
        }
    }for(i=s;i>=1;i--)printf("%d ",sol[i]);
}