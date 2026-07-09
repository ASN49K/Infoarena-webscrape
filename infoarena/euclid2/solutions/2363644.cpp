#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b, d, rest, i;
int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        rest = a % b;
        while (rest != 0)
        {
            a = b;
            b = rest;
            rest = a % b;
        }
        fout<<b<<endl;
    }

    return 0;
}
