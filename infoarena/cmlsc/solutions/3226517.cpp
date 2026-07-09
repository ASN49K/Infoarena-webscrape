#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <stack>

#define VMAX 100000
#define NMAX 1024
#define LOG 21
#define INF (int)(10e8)
#define MOD 1000000007
#define ll  long long int


using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[NMAX+1][NMAX+1];
int a[NMAX+1],b[NMAX+1];

int n,m;

int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        fin >> a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin >> b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    vector<int> lcs;
    while(dp[i][j])
    {
        if(a[i]==b[j])
        {
            lcs.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] == dp[i][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    fout << lcs.size() << "\n";
    reverse(lcs.begin(),lcs.end());
    for(int i : lcs)
    {
        fout << i << " ";
    }
}
