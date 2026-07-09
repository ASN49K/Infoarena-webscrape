#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b;

int euklidesz (int a, int b)
{
    while(b > 0)
    {
        int m = a % b;
        a = b;
        b = m;
    }

    return a;
}

int main()
{
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> a >> b;
        fout << euklidesz(a, b) << '\n';
    }
}
