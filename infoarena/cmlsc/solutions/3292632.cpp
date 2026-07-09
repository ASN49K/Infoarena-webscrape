#include<bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int dp[1050][1050],a[1050],na,b[1050],nb;
int main()
{in>>na>>nb;
stack <int>s;
for(int i=1;i<=na;i++)in>>a[i];
for(int i=1;i<=nb;i++)in>>b[i];

for(int i=1;i<=na;i++)
    for(int j=1;j<=nb;j++)
    if(a[i]==b[j])
    dp[i][j]=dp[i-1][j-1]+1;
else
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);


    out<<dp[na][nb]<<endl;
    int i=na,j=nb;
    while(dp[i][j])
    if(a[i]==b[j])
    {s.push(a[i]);
    i--;
    j--;
    }
    else
    if(dp[i-1][j]<dp[i][j-1])j--;
    else
    i--;
    while(!s.empty())
    out<<s.top()<<" ",s.pop();
}
