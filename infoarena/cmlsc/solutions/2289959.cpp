#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1025],b[1025],c[1025][1025],i,j,s[1025],l=0;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
        else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    i=n;
    j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            l++;
            s[l]=a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]>c[i][j-1])
                i--;
            else
                j--;
        }
    }
    cout<<l<<endl;
    for(i=l;i>0;i--)
        cout<<s[i]<<" ";
    return 0;
}
