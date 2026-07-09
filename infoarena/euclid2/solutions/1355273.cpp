#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream f("euclid2.in");
    std::ofstream g("euclid2.out");
    int n;
    long int x,y;
    f>>n;
    while (n-->=0) {
        f>>x>>y;
        if (y>x) {
            y+=x;x=y-x;y=y-x;
        }
        while (y%x!=0) {
            y=y%x;y+=x;x=y-x;y=y-x;
        }
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
