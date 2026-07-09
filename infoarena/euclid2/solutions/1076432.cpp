#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int t, a, b, r;

    fin>>t;

    for(int i=1;i<=t;++i)
    {
        fin>>a>>b;
        if(a>b) {r=a; a=b; b=r;}

        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }
}
