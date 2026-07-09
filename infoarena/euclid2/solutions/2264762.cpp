#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int x, y, aux, t;
    fin >> t;
    while (t > 0)
    {
    fin >> x >> y;
    while (y)
    {
        aux = y;
        y = x%y;
        x = aux;
    }
    fout << x << endl;;
    t--;
}
    return 0;
}
