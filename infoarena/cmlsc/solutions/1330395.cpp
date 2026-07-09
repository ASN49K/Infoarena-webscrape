#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,a[1030],b[1030],v[1030][1030],sir[1030];

int maxim(int x,int y)
{
    if (x>y) return x;
    return y;
}

int main()
{
    int i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (j=1;j<=m;j++)
        cin>>b[j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=maxim(v[i-1][j],v[i][j-1]);
    for (i=n,j=m;i;)
        if (a[i]==b[j])
        {
            sir[++sir[0]]=a[i];
            i--;
            j--;
        }
        else if (v[i][j-1]>v[i-1][j]) j--;
            else i--;
    cout<<sir[0]<<'\n';
    for (i=sir[0];i;i--)
        cout<<sir[i]<<" ";
}
