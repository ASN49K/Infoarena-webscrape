#include <iostream>
#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    ll n,m,a[1024],b[1024],x[1024][1024]{};
    fin>>n>>m;
    for(ll  i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(ll j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
            else x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    }
    ll i,j,k=0,rec[1024];
    i=n;
    j=m;
    while(i>=1 || j>=1)
    {
        if(a[i]==b[j])
        {
            k++;
            rec[k]=a[i];
            i--;
            j--;
        }
        else {if(x[i][j-1]>x[i-1][j]) j--;
              else i--;}
    }
    fout<<k<<endl;
    for(i=k;i>=1;i--)
    {
        fout<<rec[i]<<" ";
    }
}