#include <stdio.h>

using namespace std;
FILE *in,*out;

int n,m;
int v[1030],x[1030],a[1030][1030];

int max(int a, int b) {
    if(a<b)
        return b;
    return a;
}

void read() {
    fscanf(in,"%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        fscanf(in,"%d",&v[i]);
    for(int i=1; i<=m; i++)
        fscanf(in,"%d",&x[i]);
}

void solve() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i]==x[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);

}

void write(int l, int c) {
    if(l && c) {
        if(v[l]==x[c]) {
            write(l-1,c-1);
            fprintf(out,"%d ",v[l]);
        } else if(a[l-1][c]<a[l][c-1])
            write(l,c-1);
        else
            write(l-1,c);
    }
}

int main() {
    in=fopen("cmlsc.in","r");
    out=fopen("cmlsc.out","w");

    read();
    solve();
    fprintf(out,"%d\n",a[n][m]);
    write(n,m);
    return 0;
}
