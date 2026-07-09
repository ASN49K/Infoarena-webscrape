#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t;

int main()
{
    cin >> t;

    while(t--)
    {
        int a, b;

        cin >> a >> b;

        int r = a % b;

        while(r)
        {
            a = b;
            b = r;
            r = a % b;
        }

        cout << b << '\n';
    }

    return 0;
}
