#include <bits/stdc++.h>
#define nMax 1050

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[nMax], b[nMax], dp[nMax][nMax];
vector<int> sol;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    int i=n, j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    fout << sol.size() << "\n";
    vector<int>::reverse_iterator it;
    for(it=sol.rbegin(); it!=sol.rend(); it++)
        fout << *it << " ";
    return 0;
}
