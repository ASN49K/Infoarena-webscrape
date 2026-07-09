#include <cstdio>
#define nmMax 1056

using namespace std;

int n,m,vn[nmMax],vm[nmMax],sol[nmMax][nmMax];

int max(int x,int y) {
    return y+(x>y)*(x-y);
}

void read() {
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i) {
        scanf("%d",&vn[i]);
    }
    for(i=1;i<=m;++i) {
        scanf("%d",&vm[i]);
    }
}

void solve() {
    int i,j;
    for(i=1;i<=n;++i) {
        for(j=1;j<=m;++j) {
            if(vn[i]==vm[j]) {
                sol[i][j]=sol[i-1][j-1]+1;
            }
            else {
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
            }
        }
    }
}

void show(int i,int j) {
    for(;sol[i][j]==sol[i-1][j];--i);
    for(;sol[i][j]==sol[i][j-1];--j);
    if(i>0) {
        show(i-1,j-1);
        printf("%d ",vn[i]);
    }
}

void display() {
    int i,j;
    printf("%d\n",sol[n][m]);
    show(n,m);
}

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
    display();
    return 0;
}
