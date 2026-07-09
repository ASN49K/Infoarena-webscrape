#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const short Nmax = 1025;

int dp[Nmax][Nmax] , a[Nmax] , b[Nmax];

void Rec(int i , int j , int mx)
{
    if(!mx)
        return;
    if(a[i] == b[j])
    {
        Rec(i - 1 , j - 1 , mx - 1);
        fout << a[i] << " ";
    }
    else if(dp[i - 1][j] < dp[i][j - 1])
        Rec(i , j - 1 , mx);
    else Rec(i - 1 , j , mx);
}

int main()
{
    int n , m;
    fin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        fin >> a[i];
    for(int i = 1 ; i <= m ; i++)
        fin >> b[i];
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
    else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    Rec(n , m , dp[n][m]);
    fin.close();
    fout.close();
    return 0;
}
