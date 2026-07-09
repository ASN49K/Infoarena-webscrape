#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a, b, r, i, t;
    fin>>t;
    for(i=0; i<t; ++i)
    {
        fin>>a>>b;
        while(a%b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<b;
    }
    return 0;
}
