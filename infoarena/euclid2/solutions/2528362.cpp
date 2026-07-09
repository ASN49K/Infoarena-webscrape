#include <fstream>
#define dim 1030
using namespace std;
int a, b, r, t;
int main ()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>t;
    for (;t;t--)
    {
        fin>>a>>b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
}
