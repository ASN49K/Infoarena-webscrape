#include<fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in >> t;

    while (t--)
    {
        int n;
        in >> n;

        int s = 0;
        while (n--)
        {
            int x;
            in >> x;

            s ^= x;
        }

        if (!s) out << "NU\n";
        else out << "DA\n";
    }

}
