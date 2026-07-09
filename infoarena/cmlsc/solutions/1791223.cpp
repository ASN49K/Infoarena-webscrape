#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int s[1030][1030],  a[1030], b[1030], n, m, i, j, x, y, nr, rez[1030];

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=m; ++i)
        fin>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j){
            if(a[i]==b[j]){
                s[i][j]=s[i-1][j-1]+1;
                nr++;
                rez[nr]=a[i];
            }
            else{
                s[i][j]=s[i-1][j-1];
            }
            s[i][j]=max(max(s[i][j],s[i][j-1]), s[i-1][j]);
        }
    /*for(i=1; i<=n; ++i){
        for(j=1; j<=m; ++j){
            cout<<s[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    cout<<nr<<'\n';
    for(i=1; i<=nr; ++i)
        cout<<rez[i]<<' ';
    return 0;
}
