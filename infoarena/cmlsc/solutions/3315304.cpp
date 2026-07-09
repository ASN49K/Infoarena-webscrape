/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int n,m,v[1060],t[1060],M[1060][1060],k[1060],cnt=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int j=1;j<=m;j++)
    {
        cin>>t[j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i]==t[j])
            {
                M[i][j] = 1 + max(M[i][j-1],M[i-1][j]);
            }else
            {
                M[i][j] = max(M[i][j-1],M[i-1][j]);
            }
        }
    }
    cout<<M[n][m]<<endl;
    int i=n,j = m;
    while(i>0&&j>0)
    {
        if(v[i]==t[j])
        {
            k[++cnt] = v[i];
            i--;
            j--;
        }else if(M[i][j]==M[i][j-1])
        {
            j--;
        }else
        {
            i--;
        }
    }
    
    for(int l = cnt;l>0;l--)
    {
        cout<<k[l]<<" ";
    }
    return 0;
}