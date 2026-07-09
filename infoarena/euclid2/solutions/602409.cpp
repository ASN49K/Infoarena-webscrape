#include <fstream>
#include <cstring>

using namespace std;

ifstream in;
ofstream out;

inline int cmmdc(int a,int b)
{
    if(b!=0) return cmmdc(b,a%b);
    else return a;
}

int main()
{
    int T,a,b;

    in.open("euclid2.in");
    out.open("euclid2.out");
    in>>T;
    for(;T;--T)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
