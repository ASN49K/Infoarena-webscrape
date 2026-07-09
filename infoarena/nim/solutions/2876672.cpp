#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, n;

int main()
{
    f >> t;

    while (t--)
    {
        f >> n;

        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            int x; f >> x;
            s = s ^ x;
        }

        if (s > 0)
            g << "DA" << "\n";
        else
            g << "NU" << "\n";
    }

    return 0;
}
