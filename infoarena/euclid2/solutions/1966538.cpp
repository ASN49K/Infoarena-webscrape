#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
inline int cmmdc(int a, int b)
{
    return (b==0 ? a : cmmdc(b, a%b));
}

int main()
{
    int a, b, t;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }

}
