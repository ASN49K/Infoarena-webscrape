#include <fstream>
//http://www.infoarena.ro/problema/euclid2
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b)
        return cmmdc(b, a%b);
    return a;
}

int main()
{
    int t,i,a,b;

    fin >> t;
    for(i=1; i<=t; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
    }

    return 0;
}
