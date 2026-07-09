#include <fstream>
using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");
int main()
{
    int t, n, a;
    f>>t;
    while (t--)
    {
        f>>n;
        int sum = 0;
        while (n--)
            f>>a, sum ^= a;
        if (sum) g <<"DA\n";
        else g <<"NU\n";
    }
    return 0;
}
