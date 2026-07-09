#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b;

int main()
{
    f>>n;
    while(n)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        g<<a<<endl;
        n--;
    }
    return 0;
}
