#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

ifstream fin ("pufarina.in");
ofstream fout("pufarina.out");

const double intreg = 1000;
const int limit = 50000;

int T, N;

int CMMDC(int a, int b){
    if((!a) || (!b)) return (a + b);
    if(a>b) return CMMDC(a%b, b);
    return CMMDC(a, b%a);
}

int main()
{
    fin >> T;
    while(T--)
    {
        fin>>N;
        double x, y; int a, b, sum = 0; fin >> x; a = (x * intreg);

            for(int i = 2; i <= N; i++)
            {
                fin >> y; b = y * intreg;
                a = CMMDC(a, b);
                assert(y);
            }

            sum = (limit + limit) / a;
            if(sum >limit)
                fout<<"ALEGERI FRAUDATE\n";
            else
                fout<<sum<<'\n';
    }

    return 0;
}
