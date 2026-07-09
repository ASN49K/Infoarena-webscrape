#include <iostream>
#include <fstream>
using namespace std;
int t, a, b, i, r;
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin >> a >> b;
        while(a%b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<b<<"\n";
    }
    return 0;
}
