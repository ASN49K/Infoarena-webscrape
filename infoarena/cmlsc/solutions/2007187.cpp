#include <iostream>
#include <cstdio>
using namespace std;
int n1,n2,V1[1025],V2[1025],M[1025][1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.our","w",stdout);
    cin>>n1>>n2;
    for (int i=1;i<=n1;i++)
    {
        cin>>V1[i];
    }
    for (int i=1;i<=n2;i++)
    {
        cin>>V2[i];
    }
    for (int i=1;i<=n1;i++)
        for (int j=1;j<=n2;j++)
    {
        if (V1[i]==V2[j])
        {
            M[i][j]=M[i-1][j-1]+1;
        }
        else
            M[i][j]=max(M[i-1][j],M[i][j-1]);
    }
    cout<<M[n1][n2];
}
