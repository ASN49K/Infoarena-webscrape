#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1030],b[1030];
bool x[1030][1030];
int v[1030];
int main()
{
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++) fin>>a[i];
    for (int i=1;i<=m;i++) fin>>b[i];
    int maxim=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                bool ok=0;
                for (int k=1;k<=i&&ok==0;k++) {
                    if (x[k][j]==1) ok=1;
                }
                if (ok==0) {
                    x[i][j]=1;
                    break;
                }
            }
        }
    }
    for (int j=1;j<=m;j++) {
        for (int i=1;i<=n;i++) {
            if (x[i][j]==1) {
                maxim++,v[maxim]=j;
                break;
            }
        }
    }
    fout<<maxim<<"\n";
    for (int i=1;i<=maxim;i++) fout<<b[v[i]]<<" ";
    return 0;
}
