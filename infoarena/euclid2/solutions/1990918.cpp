#include <fstream>
using namespace std;
int main()
{
    long long a,b,r,n,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(b>a) b=b-a;
            else a=a-b;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
