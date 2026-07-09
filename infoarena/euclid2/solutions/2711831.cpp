#include <fstream>

using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int t,a,b,i,r;
int main()
{
    fi>>t;
    for(i=1;i<=t;i++)
    {
        fi>>a>>b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fo<<b<<endl;
    }
    return 0;
}
