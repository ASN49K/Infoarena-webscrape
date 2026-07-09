#include <iostream>
#include <fstream>

using namespace std;
long cmmdc(long a,long b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    long a,b;
    in>>T;
    for(int i=0;i<T;++i)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
