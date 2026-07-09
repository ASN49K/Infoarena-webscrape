#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int a,b,d;
    in>>a;
    in>>b;
    d=cmmdc(a,b);
    if(d<2)
     out<<0;
  else
    if(d>=2)
    out<<d;
    return 0;
}
