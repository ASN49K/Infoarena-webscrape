#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int s[1030][1030],  a[1030], b[1030], n, m, i, j, rez[1030], rezl;

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
            }
            else{
                s[i][j]=s[i-1][j-1];
            }
            s[i][j]=max(s[i][j], max (s[i][j-1], s[i-1][j]));
        }
    /**for(i=1; i<=n; ++i){
        for(j=1; j<=m; ++j){
            cout<<s[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    fout<<s[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0 && j>0){
        if(a[i]==b[j]){
            rez[rezl++]=a[i];
            --i;
            --j;
        }
        else{
            if(s[i-1][j] > s[i][j-1])
                --i;
            else
                --j;
        }
    }
    for(i=rezl-1; i>=0; --i)
        fout<<rez[i]<<' ';
    return 0;
}
