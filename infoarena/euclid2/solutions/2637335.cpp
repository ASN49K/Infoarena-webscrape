
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");

int main()
{
    int x, a, b, c;
    fin >> x;
    for (int i = 1, i <= x, i++)
    {
        while (a != b)
            if (a > b)
                a = a - b;
        if (b > a)
            b = b - a;

    }
    fout << a;
}
