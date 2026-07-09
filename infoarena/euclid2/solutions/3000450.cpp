#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int n, int m)
{

    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }

    return n;

}
int main()
{
    int T;
    fin >>  T;
    for(int i = 0; i < T; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << gcd(a, b) << endl;
    }

    return 0;
}
