#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    long a, b;
    f >> a >> b;
    while (a != b){
        if(a >= b) a = a - b;
        else b = b - a;
    }

    if (a == 1) a = 0;
    g << a;

    f.close();
    g.close();

}
