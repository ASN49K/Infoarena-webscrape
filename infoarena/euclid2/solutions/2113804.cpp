#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, t;

int cmmdc(int a, int b)
{
    /*
    Calculeaza cel mai mare divizor comun a doua numere date
    Input:    - int, a si b   = numerele a caror cmmdc trebuie sa il calculez
    Output:   - int           = cmmdc al numerelor data ca parametru functiei
    */
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    f >> t;
    while(t--)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
