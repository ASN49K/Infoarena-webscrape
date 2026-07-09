#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n;
long long euclid(long long x,long long y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(x>y)
        return euclid(y,x%y);
    else
        return euclid(x,y%x);
}
int main()
{
    in>>n;
    long long a,b;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
    return 0;
}
