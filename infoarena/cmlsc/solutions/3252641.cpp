#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define Nmax 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[Nmax][Nmax];
int a[Nmax],b[Nmax];
int n,m;

int cmlsc()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void write_sol()
{
    vector<int> sol;
    int i=m;
    int j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(sol.begin(),sol.end());
    for(auto poz : sol)
        fout<<poz<< " ";
}
int main()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        fin>>b[i];
    }
    int length=cmlsc();
    fout<<length<<'\n';
    write_sol();
    return 0;
}
