#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030][35];
int a[1030], b[1030], n, m;

int LSB(int x) {
    return x & ~(x-1);
}

void inherit(int x,int y){
    for (int i=0; i<35; i++)
    {
        dp[x][y][i] = dp[x-1][y][i] | dp[x][y-1][i];
    }
}

void set_found(int x, int y)
{
    int bit = y%32, idx=y/32;
    dp[x][y][idx] |= (1 << bit);
}

bool get_found(int i)
{
    int bit = i%32, idx = i/32;
    return dp[n][m][idx] & (1 << bit);
}

int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++) fin >> a[i];
    for (int i=1;i<=m;i++) fin >> b[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            inherit(i,j);
            if (a[i] == b[j])
                set_found(i,j);
        }
    }

    vector<int> result;

    for (int i=1; i<=m; i++)
    {
        if (get_found(i))
            result.push_back(b[i]);
    }

    fout << result.size() << endl;
    for (int x : result)
        fout << x << ' ';

    return 0;
}
