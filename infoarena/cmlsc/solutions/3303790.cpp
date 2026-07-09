#include <fstream>
#include <vector>

using namespace std;

ifstream be("cmls.in");
ofstream ki("cmls.out");

vector<vector<int>> dp(1025, vector<int>(1025));

int main()
{
    int n, m;
    be >> n >> m;

    vector<int> a(n + 1);
    vector<int> b(m + 1);
    
    for(int i = 1; i <= n; i++)
    {
        be >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        be >> b[i];
    }

    vector<int> nums;

    for(int i = 1; i <= n; i++)
    {

        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                nums.push_back(a[i]);
            }else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    ki << dp[n][m] << "\n";
    
    for(int i = 0; i < nums.size(); i++)
    {
        ki << nums[i] << " ";
    }

    return 0;
}