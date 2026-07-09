#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1030],b[1030],c[1030][1030],sir[1030],k,i,j,n,m;
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++) cin>>a[i];
    for(i=1; i<=m; i++) cin>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    i=n; j=m;
    while(i>0)
        if(a[i]==b[j])
            sir[++k]=a[i],i--,j--;
        else
            if (c[i-1][j]<c[i][j-1])
                j--;
            else
                i--;
    cout<<k<<"\n";
    for(i=k; i>=1; i--)
        cout<<sir[i]<<" ";

}
