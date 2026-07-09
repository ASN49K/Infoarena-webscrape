#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
inline int cmmdc(int a,int b)
{
    if(b==0) return a;
    return cmmmdc(b,a%b);
}
int main()
{
    int t,a,b;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b);
    }
}
