#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int euclid(int a, int b){
    if (!b)
        return a;
    return euclid(b, a%b);
}

int main(void)
{
    int T, a, b;

    f >> T;
    while (T>0){
        f >> a >> b;
        g << euclid(a, b) << endl;
        T--;
    }
    f.close();
    g.close();

    return 0;
}
