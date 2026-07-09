#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b, c;

int Cmmdc(int, int);

int main()
{
    fin >> n;
    while (n)
    {
        n--;
        fin >> a >> b;
        fout << Cmmdc(a, b) << '\n';
    }
}


int Cmmdc(int a, int b)
{
    int r = a % b;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
