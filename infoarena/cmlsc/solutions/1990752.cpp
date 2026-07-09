#include <iostream>
#include <fstream>
using namespace std;
int n,m,i,o,d[1025][1025],a[1025],b[1025];
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(o=1;o<=m;o++)
        {
            if(a[i]==b[o])d[i][o]=d[i-1][o-1]+1;
            else d[i][o]=max(d[i-1][o],d[i][o-1]);
        }
    }
    fout<<d[n][m];
    return 0;
}
