#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int DIM = 1030;

int v1[DIM];
int v2[DIM];

int dp[DIM][DIM];

vector <int> rez;

int main()
{
    int n, m;
    in >> n >> m;


    for(int i = 1; i <= n; i++)
        in >> v1[i];
    for(int j = 1; j <= m; j++)
        in >> v2[j];



    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
                if(v1[i] == v2[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);


        out << dp[n][m] <<'\n';


    int i = n;
    int j = m;

    while(i && j)
    {
        if(v1[i] == v2[j])
        {
            rez.push_back(v1[i]);
            i--;
            j--;
        }
        else
        if(dp[i - 1][j] > dp[i][j - 1])
        i--;
        else
        j--;
    }

    for(int i = rez.size() - 1; i >= 0; i--)
        out << rez[i] <<" ";
    return 0;
}
