#include <fstream>


using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int a[257];
int b[257];
int v[257][257];
int s[257];
int cnt;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=1+v[i-1][j-1];
            else
                v[i][j]=max(v[i-1][j], v[i][j-1]);
        }
    cout<<v[n][m]<<'\n';
    int i=n;
    int j=m;
    while(i!=0 || j!=0)
    {
        if(a[i]==b[j])
        {
            s[++cnt]=a[i];
            i--;
            j--;
        }
        else if(v[i-1][j]<v[i][j-1])
            j--;
        else i--;
    }
    for(int ii=cnt;ii>=1;ii--)
        cout<<s[ii]<<' ';

    return 0;
}
