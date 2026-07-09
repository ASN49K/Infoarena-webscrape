#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long t,a,b,r,i;
int main()
{
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
