#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T;
int main()
{
    fin>>T;
    long a,b,dc,r;
    while(fin>>a>>b)
    {
        if(b==0) dc=a;
        else
        {
            r=a%b;
            while(r)
            {
                a=b;
                b=r;
                r=a%b;
            }
            dc=b;
        }
        fout<<dc<<'\n';
    }
    return 0;
}
