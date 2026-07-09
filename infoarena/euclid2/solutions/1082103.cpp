# include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a, b, c, i, n;
int main ()
{
    f>>n;

    for(i=1; i<=n; i++)
    {
        f>>a>>b;

        while(a!=0)
        {
            c=b%a;
            b=a;
            a=c;
        }
        g<<b<<"\n";
    }

}
