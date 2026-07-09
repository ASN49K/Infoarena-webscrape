#include <bits/stdc++.h>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1030],b[1030],matrice[1030][1030],cmlsc[1030];
int main()
{
    int n,m,maxim=0;
    fin>>n>>m;
    for (int i=1;i<=n;i++) fin>>a[i];
    for (int i=1;i<=m;i++) fin>>b[i];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) matrice[i][j]=1+matrice[i-1][j-1];
            else matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
        }
    }
    for (int i=n,j=m;i&&j;) {
        if (a[i]==b[j]) cmlsc[++maxim]=a[i],i--,j--;
        else if (matrice[i-1][j]<matrice[i][j-1]) j--;
        else i--;
    }
    fout<<maxim<<"\n";
    for (int i=maxim;i>0;i--) fout<<cmlsc[i]<<" ";
    fout<<"\n";
    return 0;
}
