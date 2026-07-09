#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int cmmdc (int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }
    return 0;
}
