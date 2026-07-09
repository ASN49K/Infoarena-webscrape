#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int Euclid(int a, int b);

int main()
{
    int n, a, b;

    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";
    }

    return 0;
}

int Euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
