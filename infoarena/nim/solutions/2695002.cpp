#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int test;
    in >> test;
    for (int i = 1; i <= test; i++)
    {
        int n;
        in >> n;
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            int g;
            in >> g;
            sum ^= g;
        }
        if (sum == 0)
        {
            out << "NU";
        }
        else
        {
            out << "DA";
        }
        out << '\n';
    }
    return 0;
}
