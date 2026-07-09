#include<stdio.h>
#include<algorithm>
using namespace std;

FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");

int n,m,a[1050],b[1050],c[1050][1050];

void citire() {
    int i;

    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++) fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++) fscanf(f,"%d",&b[i]);
}

void tipar(int i,int j) {
    if(i>=1&&j>=1) {
        if(a[i]!=b[j]) {
            if(c[i-1][j]>c[i][j-1]) tipar(i-1,j);
            else tipar(i,j-1);
        }
        else {
            tipar(i-1,j-1);
            fprintf(g,"%d ",a[i]);
        }
    }

}

void solve() {
    int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]!=b[j]) c[i][j]=max(c[i-1][j],c[i][j-1]);
            else c[i][j]=c[i-1][j-1]+1;
    fprintf(g,"%d\n",c[n][m]);
    tipar(n,m);
}

int main() {

    citire();
    solve();

    return 0;
}
