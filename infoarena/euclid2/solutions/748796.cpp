#include <fstream>

using namespace std;

int cmmdc(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int N,i,a,b;
    f>>N;
    for(i=1;i<=N;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
