#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
//#include <bits/stdc++.h>
#define fastio std :: ios_base :: sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
using namespace std;

/*struct order
{
    int nod, cost;
    bool operator < (const order &x) const
    {
        return cost > x.cost;
    }
};

std::priority_queue <order> pq;
std::vector <int> v1(1030), v2(1030);
std::vector <int> :: iterator it;*/

int l1, l2, x;
int v1[1030], v2[1030], dp[1030][1030];

int main(void)
{
    //header
    {
        fastio
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        freopen("cmlsc.in", "r", stdin);
        freopen("cmlsc.out", "w", stdout);
    }

    //input
    {
        cin >> l1 >> l2;
        for(int i = 1; i <= l1; i++)
            cin >> v1[i];
        for(int i = 1; i <= l2; i++)
            cin >> v2[i];
    }

    //start of the program ->
    for(int i = 1; i <= l1; i++)
        for(int j = 1; j <= l2; j++)
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int nr = 0;
    int i, j;
    int rez[1030];
    for(i = l1, j = l2; i >= 1, j >= 1;)
    {
        if(v1[i] == v2[j])
            rez[++nr] = v1[i], i--, j--;
        else if(dp[i][j - 1] < dp[i - 1][j])
            i--;
        else
            j--;
    }

    //output
    {
        cout << dp[l1][l2] << '\n';
        for(int i = nr; i; )
            cout << rez[i] << ' ', i--;
    }
    exit(0);
}
