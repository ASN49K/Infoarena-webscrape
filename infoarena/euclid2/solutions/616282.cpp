#include <fstream>
using namespace std;
ofstream g ("euclid2.out");
void cmmdc(long int a, long int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
}
int main()
{
    ifstream f ("euclid2.in");
    long int n,a,b;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>a>>b;
        cmmdc(a,b);
    }
    f.close();
    g.close();
}
