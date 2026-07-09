#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[1024][1024];

int main()
{
    int m, n;
    in >> m >> n;

    vector<int> a(m+1), b(n+1);

    for(int i = 1; i <= m; i++) in >> a[i];
    for(int i = 1; i <= n; i++) in >> b[i];

	for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    vector<int> sir;

    for(int i = m, j = n; i; )
    {
        if(a[i] == b[j])
        {
            sir.push_back(a[i]);

            i--;
            j--;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }

    out << sir.size() << '\n';

    for(int i = sir.size() - 1; i >= 0; i--)
        out << sir[i] << ' ';

    return 0;
}
