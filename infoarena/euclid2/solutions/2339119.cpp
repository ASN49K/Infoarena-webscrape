#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if (b)
        return euclid(b, a % b);
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n, a, b;
    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }

    return 0;
}
