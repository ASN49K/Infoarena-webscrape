#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void infoarena(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //infoarena("euclid2");
    int T, a, b, r;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }

        printf("%d\n", a);
    }
    return 0;
}

