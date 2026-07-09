#include <fstream>

using namespace std;

int main()
{
    int a,n,b,c,i;
    ifstream f("joc.in");
   ofstream g("joc.out");
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a;
        f>>b;
        while (b!=0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g<<a<<endl;
    }
    return 0;
}
