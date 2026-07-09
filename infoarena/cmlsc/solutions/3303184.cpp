#include <bits/stdc++.h>

using namespace std;

ifstream in("logic.in");
ofstream out("logic.out");

int a[1026],b[1026],f[1026];
int n,m,i,j,sj,maxim,msj;
int main() {
    cin>>n>>m;
    if(n<m) {
        for (i=1;i<=n;i++)
            cin>>b[i];
        for (i=1;i<=m;i++)
            cin>>a[i];
        swap(n,m);
    }
    else {
        for (i=1;i<=n;i++)
            cin>>a[i];
        for (i=1;i<=m;i++)
            cin>>b[i];
    }
    i=1;
    sj=1;
    while (i<=n) {
        for (j=sj;j<=m;j++) {
            if (a[i]==b[j]) {
                sj=j;
                f[i]++;
            }
        }
        f[i]+=f[i-1];
        i++;
    }
    cout<<f[n]<<"\n";
    for (i=1;i<=n;i++)
        if (f[i]!=f[i-1])
            cout<<a[i]<<" ";
    return 0;
}