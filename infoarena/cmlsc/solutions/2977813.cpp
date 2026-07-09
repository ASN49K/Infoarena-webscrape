#include <fstream>
#include <deque>
#include <map>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,i,j,a[1510],b[1510],mat[1510][1510];
deque<int>v;
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1; i<=m; i++)
        cin>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    cout<<mat[n][m]<<'\n';
    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            v.push_front(a[i]);
            i--;
            j--;
        }
        else
        {
            if(mat[i][j]==mat[i-1][j])
                i--;
            else
                j--;
        }
    }
    for(auto &it:v)
        cout<<it<<" ";
    return 0;
}
