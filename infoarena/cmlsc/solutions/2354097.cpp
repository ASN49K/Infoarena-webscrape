#include <bits/stdc++.h>

using namespace std;

int m, n;
int d[1050][1050];
int a[1050], b[1050];
int prev1[1050];

int main()  {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> m >> n;
    for(int i = 1;i <= m;i++)
        cin >> a[i];
    for(int j = 1;j <= n;j++)
        cin >> b[j];
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)  {
            d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            if(a[i] == b[j])  {
                d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
            }
            if(prev1[d[i][j]] == 0)
                prev1[d[i][j]] = a[i];
        }
    cout << d[m][n] << "\n";
    for(int i = 1;i <= d[m][n];i++)
        cout << prev1[i] << " ";
    return 0;
}
