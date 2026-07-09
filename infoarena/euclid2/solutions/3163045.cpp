// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int aux;
    while (b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int main()
{
    int t, a, b;
    fin >> t;

    for (int i = 1; i <= t; i++)
    {

        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }

    fin.close();
    fout.close();
}