#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025],b[1025];
int v[1025][1025];
void recprint(int x, int y)
{
    if(not(x>0 && y>0))
    return;
    if(v[x][y-1]!=v[x][y] && v[x][y]!=v[x-1][y])
    {
        recprint(x,y-1);
        cout <<b[x]<<" ";
        return;
    }
    else if(v[x][y-1]!=v[x][y] && v[x][y]==v[x-1][y])
    {
        recprint(x-1,y);
        return;
    }
    else
    recprint(x,y-1);
    return;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin>> a[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin >> b[i];
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(b[i]==a[j])
               {
                v[i][j]=max(v[i-1][j-1]+1,v[i-1][j]);
               }
               else
               v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    cout << v[m][n]<<'\n';
    recprint(m,n);
    return 0;
}
