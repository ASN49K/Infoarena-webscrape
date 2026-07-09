#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int CMMDC(int a, int b);

int a, b, n;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a >> b;
        if (a > b)
            cout << CMMDC(a, b) << '\n';
        else
            if (a == b)
                cout << a << '\n';
            else
                cout << CMMDC(b, a) << '\n';
    }
}

int CMMDC(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    CMMDC(b, a % b);

}

