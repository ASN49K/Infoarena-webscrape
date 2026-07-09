#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,i,a,b,r;
int main()
{
    in>>n;
    for(i=1; i<=n; i++)
    {
        in>>a>>b;
        if(a==0 || b==0)
        {
            out<<a+b<<'\n';
            return 0;
        }
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        out<<b<<'\n';
    }
}
