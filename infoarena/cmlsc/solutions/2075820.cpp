#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#define NMax 1027
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B;
int sir[NMax], ans, dp[NMax][NMax], a[NMax], b[NMax];

int main()
{
    f >> A >> B;
    for(int i = 1; i <= A; ++i)
        f >> a[i];
    for(int i = 1; i <= B; ++i)
        f >> b[i];
    for(int i = 1; i <= A; ++i)
        for(int j = 1; j <= B; ++j) ///creez matricea lungimilor
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[A][B] << '\n'; /// lungimea sirului
    int i_curent = A, j_curent = B;
    while(i_curent) ///aflam care este sirul
    {
        if(a[i_curent] == b[j_curent]) /// daca sunt egale adaug in sir si merg pe diagonala in stanga sus
        {
            sir[++ans] = a[i_curent];
            --i_curent, --j_curent;
        }
        else if(dp[i_curent - 1][j_curent] < dp[i_curent][j_curent - 1]) --j_curent; /// daca val pozitiei din stanga e mai mica ca val pozitiei de sus inseamna ca mergem in stanga altfel mergem in sus
        else --i_curent;
    }

    for(int i = ans; i >= 1; --i)
        g << sir[i] << " ";
    return 0;
}
