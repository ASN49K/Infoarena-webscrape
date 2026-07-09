#include <iostream>
#include <math.h>
using namespace std;
//ifstream fin("vecine.in");
//ofstream fout("vecine.out");
long long int a[20][20];
int main()
{
    long long int n,m,v1[20],v2[20],vc[20],i,j,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)cin>>v1[i];
    for(i=1;i<=m;i++)cin>>v2[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    i=n;j=m;k=0;
    while(i>0 && j>0)
    {
        if(v1[i]==v2[j])
        {
            k++;
            vc[k]=v1[i];
            i--;j--;
        }
        else
        {
            if(a[i-1][j]>=a[i][j-1])
            {
                i--;
            }
            else j--;

        }
    }
    cout<<k<<endl;
    for(i=k;i>=1;i--)
    {
        cout<<vc[i]<<" ";
    }


    return 0;
}
