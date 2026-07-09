#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
//Daca suma XOR a elementelor din fiecare gramada este 0, atunci nu poti castiga daca incepi primul
int main()
{
    int t, suma, i, n, x;
    fin>>t;
    for(int j=1;j<=t;j++)
    {
        fin>>n;
        fin>>suma;
        for(i=2;i<=n;i++)
        {
            fin>>x;
            suma=suma^x;
        }
        if(suma==0)
            fout<<"NU"<<"\n";
        else
            fout<<"DA"<<"\n";
    }
    return 0;
}
