#include <iostream> 
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,t,i,rest;
    fin >> t;
    for(i=1;i<=t;i++)
    {
        fin >> a >> b;
        while(b)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        fout << a << "\n";

    }

    return 0;
}
