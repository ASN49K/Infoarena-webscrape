#include <bits/stdc++.h>
using namespace std;

int n,a[100][100],b[100][100],x[101],y[101],k=1,sol[100],m;


void afisare()
{
    int l=a[n][m];
    cout<<l<<endl;
    int i=n,j=m;
    while(l)
    {
        if(x[i]==y[j])
        {
            sol[l]=x[i];
            i--;
            j--;
        }
        else if(a[i-1][j]<a[i][j-1]) j--;
        else i--;
    }
    for(int i=1;i<=a[n][m];i++)
        cout<<sol[i]<<" ";
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>y[i];
    a[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    afisare();
    return 0;
}
