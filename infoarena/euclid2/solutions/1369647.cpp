#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int N;
int a,b;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    fi>>N;
    for(int i=1;i<=N;i++)
    {
        fi>>a>>b;
        fo<<gcd(a,b)<<'\n';
    }
    fi.close();
    fo.close();
    return 0;
}
