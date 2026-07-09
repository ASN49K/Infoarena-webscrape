#include <fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in >> t;
    while(t > 0)
    {
        --t;
        int n;
        int xorsum = 0;
        in >> n;
        for (int i = 1;i <= n;++i)
        {
            int nr;
            in >> nr;
            xorsum = xorsum ^ nr;
        }

        if (xorsum != 0)
            out << "DA";
        else out << "NU";
        out << '\n';
    }
    return 0;
}
