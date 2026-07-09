#include <fstream>
#include <iostream>
#include <queue>
#include <bitset>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025];
int a[1025],b[1025];
int main() {
    int n,m;
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>a[i];
    for (int i=1; i<=m; i++)
        fin>>b[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    stack<int> st;
    int val=dp[n][m];
    int i=n,j=m;
    while (i>=1 and j>=1) {
        if (dp[i][j]==val and a[i]==b[j])
            st.push(a[i]),val--,i--,j--;
        else {
            if (dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    while (!st.empty()) {
        fout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}