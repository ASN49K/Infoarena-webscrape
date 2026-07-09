#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");

int n, t, a[10005];

int main()
{
    cin >> t;

    for(int r = 1; r <= t; r++)
    {
        cin >> n;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int ok = a[1];

        for(int i = 2; i <= n; i++)
            ok = (ok ^ a[i]);

        if(!ok)
            cout << "NU\n";
        else
            cout << "DA\n";
    }

    return 0;
}
