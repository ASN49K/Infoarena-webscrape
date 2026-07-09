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
    int T, a, b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    while (T > 0)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
        T--;
    }
    return 0;
}
