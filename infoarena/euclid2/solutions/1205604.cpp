/*Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun
al numerelor din fiecare pereche in parte.*/
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int T, a, b;
    fin>>T;
    while (T--)
    {
    fin>>a>>b;
    if (b==0)
    fout<<a<<"\n";
    else
    fout<<cmmdc(a, b)<<"\n";
    }

    return 0;
}
