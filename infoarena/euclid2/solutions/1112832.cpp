#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int T, a, b, tmp;
    f >> T;
    for (int i = 0; i < T; i++) {
        f >> a >> b;
        //if (b == 0) printf("%d\n", a);
        if (a < b) { tmp = a; a = b; b = tmp; }
        while (b)
        {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        g << a << endl;
    }
    
    return 0;
}
