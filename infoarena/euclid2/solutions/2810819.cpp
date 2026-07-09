#include <iostream>
#include <fstream>

using namespace std;
int T, i, a, b, aux;

int main()
{
    ifstream f("euclid2.in");
    f>>T;
    ofstream g("euclid2.out");
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        while (b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        g<<a<<endl;
    }
    return 0;
}
