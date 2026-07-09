#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short n,m,i,j,dp[1025][1025],a[1025],b[1025],l[1025],k;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++){
        for(j=l[k]+1;j<=m;j++){
            if(a[i]==b[j]){
                l[++k]=j;
            }
        }
    }

    fout<<k<<'\n';
    for(i=1;i<=k;i++)
        fout<<b[l[i]]<<' ';

    fin.close();
    fout.close();
    return 0;
}
