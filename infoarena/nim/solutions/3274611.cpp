#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");

    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        int val = 0;

        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            val = val ^ x;
        }
        if (val == 0)
            cout << "NU\n";
        else
            cout << "DA\n";
    }

    return 0;
}
