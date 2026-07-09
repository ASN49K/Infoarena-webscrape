#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1026][1026];
int main()
{
    string s1,s2;
    stack<char> s;
    fin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=n; i >= 1;) {
        for(int j=m; j >= 1;) {
            if(s1[i-1] == s2[j-1]) {
                s.push(s1[i-1]);
                i--;
                j--;
            } else if(dp[i-1][j] < dp[i][j-1])
                j--;
            else
                i--;
        }
    }
    while(!s.empty())
    {
        fout << s.top();
        s.pop();
    }
    return 0;
}
