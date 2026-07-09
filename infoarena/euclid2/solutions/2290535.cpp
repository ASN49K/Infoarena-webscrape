#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}


int main()
{
    int T,i,x,y;
    in>>T;
    for(i=1; i<=T; i++)
    {
        in>>x>>y;
        out<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
