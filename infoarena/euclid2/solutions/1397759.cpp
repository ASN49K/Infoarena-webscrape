#include <fstream>
using namespace std;

int main()
{
    long long t,i,a,b,r;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
