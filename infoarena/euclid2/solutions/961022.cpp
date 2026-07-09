#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}


int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,c;
    f>>c;
    for(int i=1;i<=c;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
