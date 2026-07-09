#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a, int b)
{
    return (a == 0) ? b : euclid(b%a, a);
}

int main()
{
    int n, a, b;

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
    return 0;
}
