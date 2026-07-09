#include<fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,t,xs,x;
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>n;
        xs=0;
        for(int j=1;j<=n;j++)
        {
            f>>x;
            xs^=x;
        }
        if(xs) g<<"DA\n";
        else g<<"NU\n";
    }
    g.close();
    return 0;
}
