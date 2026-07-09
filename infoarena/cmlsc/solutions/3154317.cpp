/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1026],b[1026],n,m,dp[1026][1026],bst;
vector <int> v;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]){dp[i][j]=dp[i-1][j-1]+1;}
            else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
        }
    }
    int i=n,j=m;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            bst++;
            v.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            j--;
        }
        else{i--;}
    }
    fout<<bst<<'\n';
    for(int i=bst-1;i>=0;i--)
    {
        fout<<v[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
