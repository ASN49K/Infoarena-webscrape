#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

using namespace std;

int main()
{
    int T;
    int a, b, rest;
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        fin >> a >> b;
        while(b)
        {
            rest = b % a;
            a = b;
            b = rest;
        }
        fout<< a << "\n";
    }
    return 0;
}
