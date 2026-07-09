#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,c,b;

int euclid(int a, int b) {
    int c;
    while (b) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{

    ///citire date
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<endl;
    }

    return 0;
}
