#include <fstream>

using namespace std;

int Euclid (int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Read ()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int n, x, y;
    fin >> n;
    while (n--)
    {
        fin >> x >> y;
        fout << Euclid(x, y) << "\n";
    }
    fout.close();
}

int main()
{
    Read();
    return 0;
}
