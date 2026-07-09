#include <fstream>
using namespace std;
int d[1025][1025],a[1025],b[1025],rasp[1025];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            d[i][j]=max(d[i-1][j],d[i][j-1]);
            if(a[i]==b[j])
                d[i][j]=max(d[i][j],d[i-1][j-1]+1);
        }
    cout<<d[n][m]<<'\n';
    int i=n,j=m;
    while(d[i][j])
    {
        while(d[i-1][j]==d[i][j])
            i--;
        while(d[i][j-1]==d[i][j])
            j--;
        rasp[++cnt]=a[i];
        i--;
        j--;
    }
    for(int i=cnt;i>=1;i--)
        cout<<rasp[i]<<" ";
    return 0;
}
