#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int c[1025][1025];
int main()
{
    int i,j,n,m,subsir[1025],a[1025],b[1025];
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    for (j=1;j<=m;j++) cin>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    if(a[i]==b[j])  c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
    cout<<c[n][m]<<endl;
    int ret=c[n][m];
    i=n;j=m;
    while(ret>0)
    {
        if (a[i]==b[j])
        subsir[ret]=a[i],ret--,i--,j--;
        else
        if(c[i-1][j]>c[i][j-1])i--;
        else j--;
    }
        ret=c[n][m];
        for(i=1;i<=ret;i++)
            cout<<subsir[i]<<" ";
        return 0;
    }
