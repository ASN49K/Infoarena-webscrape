#include <fstream>
//http://www.infoarena.ro/problema/euclid2
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int t;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int a,i;

    fin >> a;

    int x[a], y[a];
    for(i = 1; i <= a; i++)
    {
        fin >> x[i] >> y[i];
        fout << cmmdc(x[i], y[i]) << "\n";
    }



    return 0;
}
