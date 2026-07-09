#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1025;

int n,m;
int a[NMAX], b[NMAX];
int l[NMAX][NMAX];

void afis(int i,int j){
    if(i < 1 || j < 1)
        return ;
    if(a[i] == b[j]){
        afis(i - 1,j - 1);
        fout << a[i] << ' ';
    }
    else{
        if(l[i][j] == l[i][j - 1])
            afis(i,j - 1);
        else
            afis(i - 1,j);
    }
}

int main(){

    fin >> n >> m;
    for(int i = 1;i<=n;++i)
        fin >> a[i];
    for(int j = 1;j<=m;++j)
        fin >> b[j];
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            if(a[i] == b[j])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
    fout << l[n][m] << '\n';
    afis(n,m);
    return 0;
}