#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int n1,n2,V1[1025],V2[1025],M[1025][1025],Sol[1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    ofstream g("cmlsc.out");
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
    g<<M[n1][n2]<<'\n';
    int i = n1;
    int j = n2;
    int k = 0;
    for (;i>0;i--)
        for (j=n2;j>0&&i>0;j--)
        {
            if (M[i][j]-1==M[i-1][j-1])
            {
                Sol[k]=V1[i];
                i--;
                k++;
            }
        }
    while (k>0) g<<Sol[k--];
}
