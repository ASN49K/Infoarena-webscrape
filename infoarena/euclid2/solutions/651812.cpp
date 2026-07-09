#include <fstream>

using namespace std;

ifstream in;
ofstream out;

inline int cmmdc(int a,int b)
{
    if(b==0) return a;
    for(int r=a%b;r;a=b,b=r,r=a%b);
    return b;
}

int main()
{
    int a,b,Test;

    in.open("euclid2.in");
    out.open("euclid2.out");

    in>>Test;

    for(;Test--;)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }

    in.close();
    out.close();

    return 0;
}
