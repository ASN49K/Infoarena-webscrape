#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025][1025];
int v1[1025], v2[1025];
stack <int> lcs;
int main(){
    int n, m, i, j;
    in >> n >> m;
    for (i=1; i<=n; i++)
        in >> v1[i];
    for (j=1; j<=m; j++)
        in >> v2[j];
    for (i=0; i<=n; i++)
        a[i][0]=0;
    for (j=0; j<=m; j++)
        a[0][j]=0;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++){
            if (v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
        }
    out << a[n][m] << '\n';
    i=n; j=m;
    while (a[i][j]){
        if (v1[i]==v2[j]){
            lcs.push(v1[i]);
            i--;
            j--;
        }
        else{
            if (a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    while (!lcs.empty()){
        out << lcs.top() << ' ';
        lcs.pop();
    }
}
