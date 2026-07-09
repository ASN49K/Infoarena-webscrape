#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int s1[N], s2[N];
int rez[N][N];
int n, m;
vector <int> sol;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s1[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &s2[i]);
    for (int i = 1; i <= n; i++)
        for (int i1 = 1; i1 <= m; i1++)
            if (s1[i] == s2[i1])
                rez[i][i1] = rez[i - 1][i1 - 1] + 1;
            else rez[i][i1] = max(rez[i][i1 - 1], rez[i - 1][i1]);

    for (int i = n, i1 = m; i;)
        if (s1[i] == s2[i1])
            sol.push_back(s1[i]), i--, i1--;
        else if (rez[i - 1][i1] < rez[i][i1 - 1])
            i1--;
        else i--;
    printf("%d\n", sol.size());
    for (vector <int>::reverse_iterator it = sol.rbegin(); it != sol.rend(); it++)
        printf("%d ", *it);
}
