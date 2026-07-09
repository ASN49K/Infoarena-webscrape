#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,a,b,i,r;

int main()
{
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        while(a%b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<b<<'\n';
    }
    return 0;
}
