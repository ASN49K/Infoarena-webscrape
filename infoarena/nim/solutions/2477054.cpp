#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t, n;
    fin>>t;
    for(int tt = 0; tt<t; tt++)
    {
        fin>>n;
        int k =0, o;
        for(int nn = 0; nn< n; nn++)
        {
            fin>>o;
            k = k^o;
        }
        if(k==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
