#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    if (b == 0) return a;
    return euclid (b, a%b);
}


int main()
{
    int a, b, t;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> t;
    for (;t>0;t--)
    {
        fin >> a >> b;
        fout << euclid(a,b) << endl;
    }
    return 0;
}
