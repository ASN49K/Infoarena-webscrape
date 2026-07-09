#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return cmmdc(a - b, b);
    return cmmdc(a, b - a);
}
int main()
{
    int n, a, b;
    cin >> n;
    while (cin >> a)
    {
        cin >> b;
        cout << cmmdc(a, b) << "\n";
    }
}