#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)a=a-b;
            else b=b-a;
        }
        g<<a<<endl;
    }
    return 0;
}
