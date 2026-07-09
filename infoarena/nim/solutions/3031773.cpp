#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t,x;
int main()
{
    f>>t;
    while(t--)
    {
        f>>n;
        int s=0;
        while(n--)
        {
            f>>x;
            s^=x;
        }
        if(s==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }

    return 0;
}
