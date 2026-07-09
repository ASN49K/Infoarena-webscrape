#include <fstream>
using namespace std;

int cmmdc(long a, long b)
{
    while (a != b){
        if(a >= b) a = a - b;
        else b = b - a;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long T, x, y;
    int div;
    f >> T;
    for (int i = 1; i <= T; i++){
        f >> x >> y;
        div = cmmdc(x,y);
        g << div << endl;
    }


    f.close();
    g.close();

}

