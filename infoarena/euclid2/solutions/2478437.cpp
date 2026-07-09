#include <iostream>
#include <fstream>
#define input "euclid2.in"
#define output "euclid2.out"
using namespace std;

ifstream fin(input);
ofstream fout(output);

int CMMDC(int a, int b)
{
    if(!b)
        return a;
    return CMMDC(b, a % b);
}

int main()
{
    int T, a , b;
    fin >> T;
    for(int i = 1; i <= T ; i++)
    {
        fin >> a >> b;
        fout << CMMDC(a,b) << "\n";
    }
    return 0;
}
