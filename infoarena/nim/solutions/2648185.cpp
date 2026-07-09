#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,rasp;
int main()
{f>>t;
while(t--)
{   rasp=0;
    f>>n;
    for(int i=1; i<=n; ++i)
    {
        f>>x;
        rasp=x^rasp;
    }
    if(rasp==0)
    {
        g<<"NU"<<'\n';
    }
    else
    {
        g<<"DA"<<'\n';
    }
}

    return 0;
}
