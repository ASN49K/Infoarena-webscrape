#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1024;
int dp[NMAX+5][NMAX+5];
vector<int> s1;
vector<int> s2;

int main()
{
    int n, m;
    fin>>n>>m;
    for(int i =0; i < n; i++)
    {
        int a;
        fin>>a;
        s1.push_back(a);
    }
    for(int i =0; i < m; i++)
    {
        int a;
        fin>>a;
        s2.push_back(a);
    }
    for(int i =1;i <= n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int x = max(dp[i][j-1], dp[i-1][j]);
            if(s1[i-1] == s2[j-1])
            {
                x++;
            }
            dp[i][j] = x;
        }

    }
    int i = n;
    int j = m;
    stack<int> st;
    fout<<dp[n][m]<<"\n";
    while(i!= 0 && j != 0)
    {
        if(s1[i-1] == s2[j -1])
           st.push(s1[i-1]);
        if(dp[i-1][j] > dp[i][j-1])
              i = i-1;
        else j = j -1;
    }
    while(!st.empty())
    {
        fout<<st.top()<<" ";
        st.pop();
    }
    fout<<"\n";


    return 0;
}
