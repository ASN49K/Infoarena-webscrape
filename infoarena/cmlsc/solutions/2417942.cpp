#include <fstream>
#include <algorithm>
#include <vector>
#define NMAX 1025
using namespace std;
vector<int> sir;
int a[NMAX],b[NMAX],mat[NMAX][NMAX];
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    cin>>a[i];
    for(int j=1;j<=m;++j)
    cin>>b[j];
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    if(a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];
    else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    for(int i=n,j=m;i;)
    if(a[i]==b[j])
    {
        sir.push_back(a[i]);
        --i;
        --j;
    }
    else if(mat[i-1][j]<mat[i][j-1]) --j;
    else --i;
    cout<<sir.size()<<"\n";
    for(int i=sir.size()-1;i>=0;--i)
    cout<<sir[i]<<" ";
    return 0;
}
