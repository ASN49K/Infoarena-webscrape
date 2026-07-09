#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, a, b, x, y, r;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        a = x;
        b = y;
        while(b > 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
