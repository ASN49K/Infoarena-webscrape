#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;

    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int a, b, n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << "\n";
    }
    return 0;
}
