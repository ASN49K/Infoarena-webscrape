#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,t;
int main()
{
    fin>>t;
    for(;t;t--)
    {
        fin>>a>>b;
        for(;b;)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
