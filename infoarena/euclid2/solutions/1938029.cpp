#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b,r;
int main()
{
    fin>>T;
    for(int i = 0; i < T; i++)
    {
        fin>>a>>b;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<b<<'\n';
    }
    return 0;
}
