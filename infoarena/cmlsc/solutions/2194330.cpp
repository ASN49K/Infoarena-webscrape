#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1030],b[1030];
bool x[1030];
int main()
{
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++) fin>>a[i];
    for (int i=1;i<=m;i++) fin>>b[i];
    int maxim=0,inceput=m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]&&inceput>j) x[inceput]=0,inceput=j,x[inceput]=1,maxim=1;
            else if (a[i]==b[j]) x[j]=1,maxim++;
        }
    }
    fout<<maxim<<"\n";
    for (int i=1;i<=n;i++) {
        if (x[i]) fout<<b[i]<<" ";
    }
    return 0;
}
