#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int maxn = 1025;

int n,m,a[maxn],b[maxn],d[maxn][maxn];
vector<int> v;

int main()
{
    int i,j,r;
    fin>>m>>n;
    for(i=1; i<=m; i++)
        fin>>a[i];
    for(i=1; i<=n; i++)
        fin>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    r=d[m][n];
    fout<<r<<"\n";
    while(i&&j)
        if(a[i]==b[j]) {
            v.push_back(a[i]);
            i--;
            j--;
        }
        else if (d[i-1][j] > d[i][j-1])
            i--;
        else
            j--;
    reverse(v.begin(),v.end());
    for(i=0;i<r;i++)
        fout<<v[i]<<" ";
    return 0;
}
