#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int t,nrp,x,y;

int main()
{
    f>>t;
    while(t>0)
    {
        f>>nrp;
        x=0;
        for(int i=1;i<=nrp;)
        {
            f>>y;
            x=x^y;
        }
        if(x>0)g<<"DA"<<'\n';
        else g<<"NU"<<'\n';
        t--;
    }

    f.close();g.close();
    return 0;
}

