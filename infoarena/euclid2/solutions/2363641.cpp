#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b, d, rest, i, nrmare, nrmic;
int main()
{
    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>a>>b;
        if(a>b)
        {
            nrmic=b;
            nrmare=a;
        }
        else
        {
            nrmic=a;
            nrmare=b;
        }
        while(nrmic!=0)
        {
            rest=nrmare%nrmic;
            nrmare=nrmic;
            nrmic=rest;
        }
        fout<<nrmare<<endl;
    }

    return 0;
}
