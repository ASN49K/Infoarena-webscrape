#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n=0;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        f>>a>>b;
        while(a!=0)
        {
            int r=b%a;
            b=a;
            a=r;
        }
        g<<b<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
