#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b, d, r;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
    return 0;
}
