#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,i,j,h,x,y;

    f>>t;
    for(i=1;i<=t;i++)
    {
        x=0;
        f>>h;
        for(j=1;j<=h;j++)
        {
            f>>y;
            x=x^y;
        }
        if(x) g<<"DA\n";
        else g<<"NU\n";
    }

    f.close();
    g.close();
    return 0;
}
