#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int m, n;
    in >> m >> n;

    vector<int> a(m), b(n);

    for(int i = 0; i < m; i++) in >> a[i];
    for(int i = 0; i < n; i++) in >> b[i];

    int dp[1024] = {0};

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            dp[j] = max(dp[j], dp[j-1] + (a[i] == b[j]));

    out << dp[n-1];

    return 0;
}
