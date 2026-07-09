#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t, n, nr, rez;
    cin >> t;
    while(t > 0)
    {
        t--;
        cin >> n;
        rez = 0;
        while(n > 0)
        {
            n--;
            cin >> nr;
            rez = rez ^ nr;
        }
        if(rez == 0)
            cout << "NU" << '\n';
        else
            cout << "DA" << '\n';
    }
    return 0;
}
