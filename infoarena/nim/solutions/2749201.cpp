#include <fstream>

using namespace std;

int main()
{
    ifstream in("nim.in");
    ofstream out("nim.out");

    int t;

    in >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        int sol;

        in >> n;

        in >> sol;

        for (int j = 2; j <= n; j++)
        {
            int x;

            in >> x;

            sol ^= x;
        }

        if (sol == 0)
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
