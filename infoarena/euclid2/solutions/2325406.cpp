#include <iostream>
#include <fstream>
using namespace std;

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");

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
