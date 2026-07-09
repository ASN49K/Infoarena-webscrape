#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    while(a>0 and b>0)
    {
        if(a>b) a=a%b;
            else b=b%a;
    }
    return max(a,b);
}

int main()
{
    ifstream mama("euclid2.in");
    ofstream tata("euclid2.out");

    int n,a,b,i;

    mama>>n;

    for(i=1;i<=n;i++)
    {
        mama>>a>>b;
        tata<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
