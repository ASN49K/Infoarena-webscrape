#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n,t,i,j;
long int nr,s;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        {
            f>>t;
            f>>s;
            for(j=2;j<=t;j++)
            {
                f>>nr;
                s^=nr;
            }
            if(s>0)
                g<<"DA"<<"\n";
            else
                g<<"NU"<<"\n";
        }
    f.close();g.close();
}
