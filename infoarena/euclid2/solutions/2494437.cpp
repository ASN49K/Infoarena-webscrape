#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int x,a,b,rest;
    cin >> x;
    for (int i = 1; i <= x; i ++)
    {
        cin >> a >> b;
        while (b)
        {
            rest= a % b;
            a   = b;
            b   = rest;
        }
        cout << a << "\n";
    }
    return 0;
}
