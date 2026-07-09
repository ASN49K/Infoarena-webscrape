#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int cmmdc(int a, int b)
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
    f>>n;
    for(int i=1;i<=n;i++)
        {f>>a>>b;
         g<<cmmdc(a,b)<<endl;
        }
    return 0;
}
