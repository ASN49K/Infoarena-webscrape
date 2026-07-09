#include <fstream>
//http://www.infoarena.ro/problema/euclid2
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b!=0) return cmmdc(b, a%b);
    else return a;
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
