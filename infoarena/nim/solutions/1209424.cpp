#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n,x,p,y,i;

int main()
{
    for(f>>p;p;p--)
    {
        f>>n;
        for(x=i=0;i<n;i++)f>>y,x^=y;
        if(x)g<<"DA"<<"\n";
        else g<<"NU"<<"\n";
    }
    return 0;
}
