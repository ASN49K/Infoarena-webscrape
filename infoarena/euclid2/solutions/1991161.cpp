#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T;
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f >> T;
    int x, y;
    for (int i = 0; i < T; i++)
    {
        f >> x >> y;
        while (y)
        {
            int r = x % y;
            x = y;
            y = r;
        }
        g << x << endl;
    }
    return 0;
}
