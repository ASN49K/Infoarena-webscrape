#include <bits/stdc++.h>
#define QED fin.close(); fout.close(); return 0;
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
#define cin fin
#define cout fout

int main()
{
    int t, n, x, s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s = 0;
        while(n--)
        {
            cin >> x;
            s ^= x;
        }
        cout << (s != 0 ? "DA\n" : "NU\n");
    }
    QED
}
