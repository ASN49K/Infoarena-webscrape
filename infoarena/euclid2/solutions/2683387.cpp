#include <fstream>
using namespace std;
int main()
{
    ifstream fin("euclid2.in"); ofstream fout("euclid2.out");
    long long unsigned a, b, t, r;
    fin >> t;
    while (t--)
    {
        fin >> a;
        fin >> b;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
