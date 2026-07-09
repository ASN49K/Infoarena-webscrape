#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1024],b[1024],d[1024][1024],sir[1024],k,n,m;

int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=m;i++)
    {
        cin >> b[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    int i=n,j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j])
        {
            sir[++k]=a[i];
            i--;
            j--;
        }
        else if (d[i-1][j]>d[i][j-1])
        {
            i--;
        }
        else j--;
    }
    for (int i=k;i>=1;i--)
    {
        cout << sir[i] << " ";
    }
}
