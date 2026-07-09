#include <fstream>
#include <vector>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << cmmmdc(x, y) << '\n';
    }
}