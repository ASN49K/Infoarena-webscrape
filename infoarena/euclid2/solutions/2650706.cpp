#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b,c,n,i;

int main()
{
    f>>n;

    for(i=1;i++;i<=n)
    {
        f>>a>>b;

        while (a!=b)
        {
            c=a%b;
            a=b;
            b=c;
        }

        g<<a<<endl;
    }


    return 0;
}
