#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,r,i;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
    do{
        r=a%b;
        a=b;
        b=r;
    } while(r!=0);
    g<<a<<'\n';
    }
    return 0;
}
