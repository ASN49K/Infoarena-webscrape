#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int n,i,a,b;

int cmmdc(int a, int b)
{
    if(b>0)
        return cmmdc(b,a%b);
    return a;
}

int main()
{
    fi>>n;
    for(i=1; i<=n; i++)
    {
        fi>>a>>b;
        fo<<cmmdc(a,b)<<"\n";
    }
    fi.close();
    fo.close();
    return 0;
}
