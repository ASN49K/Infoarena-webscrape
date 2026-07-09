#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    vector<int> w(m+1);
    vector<vector<int>> d(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(v[i] == w[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }
    cout << d[n][m] << "\n";
    vector<int> ans;
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(v[i] == w[j])
        {
            ans.push_back(v[i]);
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j] > d[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        cout << *it << " ";
    }
}