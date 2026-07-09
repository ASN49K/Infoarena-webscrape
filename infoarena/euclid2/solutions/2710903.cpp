#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int cmmdc(int a, int b)
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

int main()
{
    fin >> n;

    int a, b;

    while (n)
    {
        fin >> a >> b;

        fout << cmmdc(a, b) << '\n';

        n--;
    }

    fin.close();
    fout.close();
    return 0;
}
