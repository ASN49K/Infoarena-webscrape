#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int n,i,a,b;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }

    return 0;
}
