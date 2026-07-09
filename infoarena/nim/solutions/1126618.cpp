#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T, N, S;

int main()
{
    fin >> T;
    while(T--)
    {
        fin >> N; S = 0;
        for(int i = 1; i <= N; i++)
        {
            int x; fin >> x;
            S ^= x;
        }
        if(S) fout<<"DA\n";
        else fout <<"NU\n";
    }
    return 0;
}
