#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,r,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        r=b%a;
        while(r!=0)
        {
            b=a;
            a=r;
            r=b%a;
        }
        fout<<a<<'\n';
    }
    return 0;
}
