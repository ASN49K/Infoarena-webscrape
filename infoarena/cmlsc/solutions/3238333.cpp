#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, v[1025][1025], a[1025], b[1025], sol[1025], cnt;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
    for(int i=n,j=m;i>=1;)
    {
        if(v[i][j]== v[i-1][j-1]+1)
        {
            sol[++cnt]=a[i];
            i--;
            j--;
        }
        else if(v[i][j-1]>v[i-1][j])
        j--;
        else
            i--;
    }
    for(int i=cnt;i>=1;i--)
        cout<<sol[i]<<" ";
}
