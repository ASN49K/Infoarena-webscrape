#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int a[1025]={0}, b[1025]={0}, d[1025][1025]={0}, s[1025], i, j, m, n, l = 0;
    f >> n >> m;
    for(i=1; i<=n; i++)
        f >> a[i];
    for(i=1; i<=m; i++)
        f >> b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i] == b[j]){
                d[i][j] = 1 + d[i-1][j-1];
            }
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
    g << d[n][m] << "\n";
    for(i=n, j=m; i;){
        if(a[i] == b[j]){
            s[++l] = a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] > d[i][j-1])
            i--;
        else j--;
    }
    for(i=1; i<=l; i++)
        g << s[i] << " ";
}
