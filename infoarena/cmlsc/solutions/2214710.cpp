#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1024],b[1024],r[1000];
int n,m,p[1024][1024];

int main()
{
    in >> n >> m;
    for(int i=1; i<=n; i++){
        in >> a[i];
    }
    for(int i=1; i<=m; i++){
        in >> b[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i]==b[j]) p[i][j] = p[i-1][j-1] + 1;
            else p[i][j] = max(p[i-1][j],p[i][j-1]);
        }
    }

    out << p[n][m] << "\n";
    int rez;
    int i = n, j = m;
    while(i && j){
        if(a[i]==b[j]) {r[++rez] = a[i]; i--; j--;}
        else if (p[i-1][j]>p[i][j-1]) i--;
        else j--;
    }
    for(int i = rez; i>0; i--){
        out << r[i] << " ";
    }
    return 0;
}
