#include <fstream>
#include <queue>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


void euclid(int a, int b)
{
    int r;
    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    fout << a << '\n';
}

int main()
{
    int n, i, a, b;

    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> a >> b;
        euclid(a, b);
    }


    return 0;
}
