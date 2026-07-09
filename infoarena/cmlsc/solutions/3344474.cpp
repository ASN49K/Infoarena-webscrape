#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025];
int dp[1025][1025];
int main() {
    int n,m;
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>a[i];
    for (int i=1; i<=m; i++)
        fin>>b[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            dp[i][j]=dp[i-1][j-1];
            if (a[i]==b[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
            else
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    int val=dp[n][m];
    stack<int> st;
    for (int i=n; i>=1; i--)
        for (int j=m; j>=1; j--)
            if (dp[i][j]==val and a[i]==b[j])
                st.push(a[i]),val--;
    fout<<st.size()<<"\n";
    while (!st.empty()) {
        fout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
// 2 0 3 -1 7 -4
