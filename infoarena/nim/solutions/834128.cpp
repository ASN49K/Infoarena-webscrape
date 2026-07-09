#include<fstream>
using namespace std;
int n,t,i,j,rez,x;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    while(t--)
    {
        f>>n;
        rez=0;
        for(i=1;i<=n;i++)
        {
            f>>x;
            rez=rez^x;
        }

        if(rez)
            g<<"DA\n";
        else
            g<<"NU\n";
    }

    return 0;
}
