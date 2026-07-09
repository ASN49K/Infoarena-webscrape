#include <fstream>

using namespace std;

const int TMAX = 100000;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void euclid(int a, int b, int &d, int &x, int &y)
{
    if(b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main()
{
    int T, a, b;
    fin >> T;

    for(int i = 0; i < T; i++)
    {
        int d, x, y;
        fin >> a >> b;
        euclid(a, b, d, x, y);
        fout << d << endl;
    }
    return 0;
}
