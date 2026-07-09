#include <iostream>
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

    int t;
    fin >> t;
    while (t)
    {
        int a, b;
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
        --t;
    }
    return 0;
}
