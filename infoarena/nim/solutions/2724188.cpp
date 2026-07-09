#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int teste, n, opera;

long long suma;

const int NMAX = 10005;

int v[NMAX];

int main()
{
    fin>>teste;
    while(teste>0)
    {
        fin>>n;
        for(int i=1; i<=n; i++)
        {
            fin>>v[i];
            opera ^=v[i];
        }
        teste--;
        if(opera)
            fout<<"DA"<<"\n";
        else
            fout<<"NU"<<"\n";
    }
    return 0;
}
