#include <iostream>
#include <fstream>
using namespace std;

int gcd (int a, int b)
{
    int r = a%b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, a, b;

    fin >> T;

    while (T > 0)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<"\n";
        T--;
    }
    fin.close();
    fout.close();
    return 0;
}
