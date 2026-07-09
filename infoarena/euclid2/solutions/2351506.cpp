#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, aux;
    fin>>t;
    for(int i = 1; i <= t; i++)
    {
        fin>>a>>b;
        while(b != 0)
        {
            a = a % b;
            aux = b;
            b = a;
            a = aux;

        }
        fout<<a<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
