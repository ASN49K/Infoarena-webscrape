#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b)
        return a;
    return cmmdc(b, a % b);
}

int cmmmc(int a, int b)
{
    return (a * b) / cmmdc(a, b);
}

int main()
{
    int n;
    int x, y;

    fin >> n;

    while(n--)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }

    return 0;
}

