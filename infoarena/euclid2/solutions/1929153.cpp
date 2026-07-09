#include <fstream>

using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int t,i,X[100001],a,b;

int euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    fi>>t;
    for(i=1;i<=t;i++)
    {
        fi>>a>>b;
        fo<<euclid(a,b)<<'\n';
    }

    return 0;
}
