#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1505],b[1505],d[1505][1505],sol[1505];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    int cnt=0;
    int i=n,j=m;
    while(i>=1 and j>=1)
    {
        if(a[i]==b[j])
        {
            cnt++;
            sol[cnt]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout<<cnt<<'\n';
    for(int i=cnt; i>=1; i--)
    {
        cout<<sol[i]<<" ";
    }
    return 0;
}
