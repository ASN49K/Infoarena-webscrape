#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, n, a[10050];

void solve()
{
    int rez=0;
    for(int i=0; i<n; i++){
        rez = rez^a[i];
    }
    if(rez!=0)
        printf("DA\n");
    else
        printf("NU\n");
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        for(int j=0; j<n; j++)
            scanf("%d", &a[j]);
        solve();
    }
    return 0;
}
