#include <fstream>
#include <cstring>

#define valoareaUVS 1000000000

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int test,n,a[10001];

void Mai_taie_din_ele_dale_dreacu (int &n)
{
    --n;
}

void REZOLVA_NIM (int n)
{
    if (n)  //mai sunt pietre
    {
        Mai_taie_din_ele_dale_dreacu (n);
        REZOLVA_NIM (n);
    }
    else
    {
        fout<<"Gata am castigat $$$";
    }
}

int main()
{
    int n;
    fin>>test;

    for (;test; --test)
    {
        fin>>n;
        int s = 0;

        for (int i=1; i<=n; ++i)
         {
             fin>>a[i];
             s += a[i];
         }

         //CE-MI PASA MIE CARE IN CE MULTIME ESTE, DA-LE DREACU
         memset (a,0,sizeof(a));

        //STAI CA AM O SOLUTIE MAI BUNA LA PROBLEMA ASTA

        REZOLVA_NIM (s);
    }

            //UPS A LUAT ZERO
}
