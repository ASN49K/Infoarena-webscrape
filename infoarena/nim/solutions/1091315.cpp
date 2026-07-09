#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T, N, V, SOL;

int main()
{
    fin >> T;
    while(T--)
    {
        fin >> N; SOL = 0;
        for(int i = 1; i <= N; i++)
        {
            fin >> V;
            SOL = SOL ^ V;
        }

        if(SOL) fout<<"DA";
        else    fout<<"NU";
        fout<<endl;
    }
    return 0;
}
