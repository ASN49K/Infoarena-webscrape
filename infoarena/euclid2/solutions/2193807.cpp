#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a, b, t;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        while(b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        cout << a << "\n";
    }

    return 0;
}
