#include <fstream>

int cmmd(int x, int y);

int main(void)
{
    std::ifstream fin("euclid2.in", std::ios::in);
    std::ofstream fout("euclid2.out", std::ios::out);
    int t;
    fin >> t;
    for (int i = 0; i<t; i++)
    {
        int a,b;
        fin >> a >> b;
        fout << cmmd(a,b) << "\n";
    };
    fout.close();
    fin.close();
}

int cmmd(int x, int y)
{
    if (!y)
        return x;
    return cmmd(x, x % y);
}
