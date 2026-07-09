#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int m,n,i,j,sol,mx,a[1050],b[1050],s[100],k;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
    {
        if (sol>mx)
           {
               mx=sol;
               for(int l=1;l<k;l++)
                s[l]=0;
           }
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
                {
                    sol++;
                    s[++k]=a[i];
                }
    }
    }
    cout<<sol<<endl;
    for(i=1;i<=k;i++)
        cout<<s[i]<<" ";

    return 0;
}
