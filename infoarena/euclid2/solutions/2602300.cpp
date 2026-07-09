#include <fstream>

ifstream fin("euclid.in")
ofstream fout("euclid.out")

using namespace std;

int main()
{
    int a, b, rest;
    int x
    fin >> a >> b;
    while(b != 0)
    {
         rest = a % b;
         a = b;
         b = rest;
    }
    fout << a;
    return 0;
}
