#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
inline int cmmdc(int a,int b)
{
    if(b==0) return a;
    return cmmdc(b,a%b);
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
