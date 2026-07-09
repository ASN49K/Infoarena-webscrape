#include<cstdio>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<unordered_map>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

int t, n, xorsum, x;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &t);

    for(; t; t--)
    {
        scanf("%d", &n);

        for(xorsum = 0; n; n--)
        {
            scanf("%d", &x);
            xorsum ^= x;
        }

        printf("%s\n", xorsum ? "DA" : "NU");
    }
    return 0;
}
