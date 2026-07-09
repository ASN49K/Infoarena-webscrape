#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v[1000],v2[1000],a[1000][1000],sol[1000];
int n,m,nr,i,j;

int main()
{
    f>>n>>m;
    for(i = 0 ; i < n; i++)
        f>>v[i];
    for(i = 0 ; i < m; i++)
        f>>v2[i];
    for(i = 0; i < n ; i++){
        for(j = 0 ; j < m; j++){
            if(v[i] == v2[j])
                a[i][j] = a[i-1][j-1]+1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
        g<<a[n][m]<<endl;
        i = n; j = m;
        while(i>=1 && j>=1)
        {
            if(v[i] == v2[j])
            {
                nr++;
                sol[nr] = v[i];
                i--;
                j--;
            }
            else
                if(a[i-1][j] > a[i][j-1])
                i--;
            else
                j--;
        }
        for(i = nr;i>=1;i--)
            g<<sol[i]<<' ';
        return 0;
    }
}
