#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int teste, n, opera;

//long long suma;

const int NMAX = 10005;

int v[NMAX];

int main()
{
    fin>>teste;
    for(int i=1; i<=teste; i++)
    {
        fin>>n;
        for(int j=1; j<=n; j++)
        {
            fin>>v[j];
            opera ^=v[j];
        }
        if(opera!=0)
            fout<<"DA"<<"\n";
        else
            fout<<"NU"<<"\n";
    }
    return 0;
}
