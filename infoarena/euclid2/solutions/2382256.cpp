#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, c;
    fin >> t;
    for (int i=0; i<t; i++)
    {
        fin >> a >> b;
        while (b!=0)
        {
            c = b;
            b = a%b;
            a = c;
        }
        fout << a << '\n';
    }
    return 0;
}
