#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n;
void read()
{
    int S=0,val;
    int i;
    f>>t;
    while(t--)
    {
        f>>n;
        S=0;
        while(n--)
        {
            f>>val;
            S^=val;
        }
        if(S==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }
}
int main()
{
    read();
    return 0;
}
