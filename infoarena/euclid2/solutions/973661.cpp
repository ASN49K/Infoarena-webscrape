#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,j,x,y,t;
int euc(int a,int b)
{
    if(b==0)
        return a;
    return euc(b,a%b);
}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<euc(x,y)<<'\n';
    }
    return 0;
}
