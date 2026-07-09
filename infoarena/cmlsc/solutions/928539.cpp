#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1030],b[1030],l[1030][1030];
int n,m;

int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        in >> a[i];
    for (int i = 1; i <= m; ++i)
        in >> b[i];
    for (int i = 1; i <=n; ++i)
        for (int j = 1; j <= m; ++j)
        if (a[i] == b[j]) l[i][j] = l[i-1][j-1] + 1;
        else l[i][j] = max(l[i][j-1],l[i-1][j]);


    int k = l[n][m];
    out << k << '\n';
    vector<int> sol;

    while (k)
    {
        while (l[n][m-1] == k) --m;
        while (l[n-1][m] == k) --n;
        sol.push_back(a[n]);
        n--; m--; k--;
    }

    for (int i = sol.size()-1; i >= 0; --i)
        out << sol[i] << " ";
    in.close();
    out.close();
    return 0;
}
