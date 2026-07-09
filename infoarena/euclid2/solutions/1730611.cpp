#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a, b, n;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
