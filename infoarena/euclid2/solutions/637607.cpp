#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
    if(a%b==0)return b;
    return cmmdc(b,a%b);
}

int main()
{
    int a,b,T;
    in>>T;
    while(T--)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
