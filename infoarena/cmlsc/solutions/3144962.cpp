#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1026][1026],m,n,s1[1026],s2[1026];
int main()
{
    stack<int> s;
    fin >> m >> n;
    for(int i=1; i <= m; i++)
        fin >> s1[i];
    for(int i=1; i <= n; i++)
        fin >> s2[i];
    for(int i=1; i <= m; i++) {
        for(int j=1; j <= n; j++) {
            if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=m; i >= 1;) {
        for(int j=n; j >= 1;) {
            if(s1[i] == s2[j]) {
                s.push(s1[i]);
                i--;
                j--;
            } else if(dp[i-1][j] < dp[i][j-1])
                j--;
            else
                i--;
        }
    }
    fout << dp[m][n] << '\n';
    while(!s.empty()) {
        fout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
