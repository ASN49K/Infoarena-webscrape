#include <fstream>
using namespace std;
ifstream f ("algoritm.in");
ofstream g ("algoritm.out");
int n,a,b;
int main()
{
    int i,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
       f>>a>>b;
       while(b)
       {
        r=a%b;
        a=b;
        b=r;
       }
       g<<a<<'\n';
    }
    return 0;
}
