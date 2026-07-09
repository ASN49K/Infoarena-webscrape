#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b, d, rest, i;
int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        fout<<a<<endl;
    }

    return 0;
}
