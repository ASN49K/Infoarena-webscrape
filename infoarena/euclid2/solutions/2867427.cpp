#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream fin("fis.in");
ofstream fout("fis.out");
int t,r,a,b;
int main()
{
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
        t--;
    }
    return 0;
}
