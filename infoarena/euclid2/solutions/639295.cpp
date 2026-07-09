#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void cmmdc2(int a,int b,int &d)
{
    if(b==0)d=a;
    else cmmdc2(b,a%b,d);
}

int cmmdc(int a,int b)
{
    if(a%b==0)return b;
    return cmmdc(b,a%b);
}

int main()
{
    int a,b,T,d;
    in>>T;
    while(T--)
    {
        in>>a>>b;
        //out<<cmmdc(a,b)<<'\n';
        cmmdc2(a,b,d);
        out<<d<<'\n';
    }
    return 0;
}
