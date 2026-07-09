#include<bits/stdc++.h>

using namespace std;

void query()
{
    int a, b, r;
    cin >> a >> b;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    cout << a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;
    cin >> t;
    while(t--)
    {
        query();
        cout << "\n";
    }

}