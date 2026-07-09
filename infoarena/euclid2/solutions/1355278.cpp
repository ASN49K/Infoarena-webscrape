#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream f("euclid2.in");
    std::ofstream g("euclid2.out");
    int n;
    long int x,y,aux;
    f>>n;
    while (--n>=0) {
        f>>x>>y;
        if (y>x) {
            aux=y;
            y=x;
            x=aux;
        }
        while (y%x!=0) {
            aux=y%x;
            y=x;
            x=aux;
        }
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
