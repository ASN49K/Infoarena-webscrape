#include<fstream>
#include<stack>
#define NMAX 1205
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, m, i, j;
int a[NMAX], b[NMAX], d[NMAX][NMAX];
stack<int> sol;
int main()
{
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }else
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    i = n;
    j = m;
    while(i != 0 && j != 0)
    {
        if(a[i] == b[j])
        {
            sol.push(a[i]);
            i--;
            j--;
            continue;
        }
        if(d[i - 1][j] > d[i][j - 1])
        {
            i--;
        }else
        {
            j--;
        }
    }
    cout << d[n][m] << "\n";
    while(!sol.empty())
    {
        cout << sol.top() << " ";
        sol.pop();
    }
    return 0;
}


























