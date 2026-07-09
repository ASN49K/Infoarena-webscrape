#include <iostream>
#include <fstream>

using namespace std;

long a, b, r;
int T, i;

long cmmdc(long a, long b)
{
    while(b>0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> T;
    for(i=1; i<=T; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    fin.close();
    return 0;
}
